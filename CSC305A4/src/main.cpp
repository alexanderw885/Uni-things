
////////////////////////////////////////////////////////////////////////////////
// C++ include
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>
#include <algorithm>
#include <numeric>

// Utilities for the Assignment
#include "utils.h"

// Image writing library
#define STB_IMAGE_WRITE_IMPLEMENTATION // Do not include this line twice in your project!
#include "stb_image_write.h"

// Shortcut to avoid Eigen:: everywhere, DO NOT USE IN .h
using namespace Eigen;

////////////////////////////////////////////////////////////////////////////////
// Class to store tree
////////////////////////////////////////////////////////////////////////////////
class AABBTree
{
public:
    class Node
    {
    public:
        AlignedBox3d bbox;
        int parent;   // Index of the parent node (-1 for root)
        int left;     // Index of the left child (-1 for a leaf)
        int right;    // Index of the right child (-1 for a leaf)
        int triangle; // Index of the node triangle (-1 for internal nodes)
    };

    std::vector<Node> nodes;
    int root;

    AABBTree() = default;                           // Default empty constructor
    AABBTree(const MatrixXd &V, const MatrixXi &F); // Build a BVH from an existing mesh

private:
    // builds the bvh recursively
    int build_recursive(const MatrixXd &V, const MatrixXi &F, const MatrixXd &centroids, int from, int to, int parent, std::vector<int> &triangles);
};

////////////////////////////////////////////////////////////////////////////////
// Scene setup, global variables
////////////////////////////////////////////////////////////////////////////////
const std::string data_dir = DATA_DIR;
const std::string filename("raytrace.png");
const std::string mesh_filename(data_dir + "bunny.off");
const bool bonus = false;

//Camera settings
const double focal_length = 2;
const double field_of_view = 0.7854; //45 degrees
const bool is_perspective = true;
const Vector3d camera_position(0, 0, 2); // (0,0,2)

// Triangle Mesh
MatrixXd vertices; // n x 3 matrix (n points)
MatrixXi facets;   // m x 3 matrix (m triangles)
AABBTree bvh;

// Bonus marks setup
// Objects
std::vector<Vector3d> sphere_centers;
std::vector<double> sphere_radii;
std::vector<Matrix3d> parallelograms;
//Maximum number of recursive calls
const int max_bounce = 5;

//Material for the object, same material for all objects
const Vector4d obj_ambient_color(0.0, 0.5, 0.0, 0);
const Vector4d obj_diffuse_color(0.5, 0.5, 0.5, 0);
const Vector4d obj_specular_color(0.2, 0.2, 0.2, 0);
const double obj_specular_exponent = 256.0;
const Vector4d obj_reflection_color(0.7, 0.7, 0.7, 0);

// Precomputed (or otherwise) gradient vectors at each grid node
const int grid_size = 20;
std::vector<std::vector<Vector2d>> grid;

//Lights
std::vector<Vector3d> light_positions;
std::vector<Vector4d> light_colors;
//Ambient light
const Vector4d ambient_light(0.2, 0.2, 0.2, 0);

//Fills the different arrays
void setup_scene()
{
    //Loads file
    std::ifstream in(mesh_filename);
    std::string token;
    in >> token;
    int nv, nf, ne;
    in >> nv >> nf >> ne;
    vertices.resize(nv, 3);
    facets.resize(nf, 3);
    for (int i = 0; i < nv; ++i)
    {
        in >> vertices(i, 0) >> vertices(i, 1) >> vertices(i, 2);
    }
    for (int i = 0; i < nf; ++i)
    {
        int s;
        in >> s >> facets(i, 0) >> facets(i, 1) >> facets(i, 2);
        assert(s == 3);
    }

    //setup tree
    bvh = AABBTree(vertices, facets);

    //Lights
    // light_positions.emplace_back(8, 8, 0);
    // light_colors.emplace_back(4, 4, 4, 0);

    light_positions.emplace_back(6, -8, 0);
    light_colors.emplace_back(16, 16, 16, 0);

    light_positions.emplace_back(4, 8, 0);
    light_colors.emplace_back(16, 16, 16, 0);

    light_positions.emplace_back(2, -8, 0);
    light_colors.emplace_back(16, 16, 16, 0);

    light_positions.emplace_back(0, 8, 0);
    light_colors.emplace_back(16, 16, 16, 0);

    light_positions.emplace_back(-2, -8, 0);
    light_colors.emplace_back(16, 16, 16, 0);

    light_positions.emplace_back(-4, 8, 0);
    light_colors.emplace_back(16, 16, 16, 0);

    // bonus mark setup
    //Spheres
    sphere_centers.emplace_back(10, 0, 1);
    sphere_radii.emplace_back(1);

    sphere_centers.emplace_back(7, 0.05, -1);
    sphere_radii.emplace_back(1);

    sphere_centers.emplace_back(4, 0.1, 1);
    sphere_radii.emplace_back(1);

    sphere_centers.emplace_back(1, 0.2, -1);
    sphere_radii.emplace_back(1);

    sphere_centers.emplace_back(-2, 0.4, 1);
    sphere_radii.emplace_back(1);

    sphere_centers.emplace_back(-5, 0.8, -1);
    sphere_radii.emplace_back(1);

    sphere_centers.emplace_back(-8, 1.6, 1);
    sphere_radii.emplace_back(1);


    //parallelograms
    parallelograms.emplace_back();
    parallelograms.back() << -100, 100, -100,
        -1.25, 0, -1.2,
        -100, -100, 100;
}

////////////////////////////////////////////////////////////////////////////////
// BVH Code
////////////////////////////////////////////////////////////////////////////////

AlignedBox3d bbox_from_triangle(const Vector3d &a, const Vector3d &b, const Vector3d &c)
{
    AlignedBox3d box;
    box.extend(a);
    box.extend(b);
    box.extend(c);
    return box;
}

AABBTree::AABBTree(const MatrixXd &V, const MatrixXi &F)
{
    // Compute the centroids of all the triangles in the input mesh
    MatrixXd centroids(F.rows(), V.cols());
    centroids.setZero();
    for (int i = 0; i < F.rows(); ++i)
    {
        for (int k = 0; k < F.cols(); ++k)
        {
            centroids.row(i) += V.row(F(i, k));
        }
        centroids.row(i) /= F.cols();
    }

    //Vector containing the list of tringle indices
    std::vector<int> triangles(F.rows());
    std::iota(triangles.begin(), triangles.end(), 0);

    root = build_recursive(V, F, centroids, 0, triangles.size(), 0, triangles);

}

int AABBTree::build_recursive(const MatrixXd &V, const MatrixXi &F, const MatrixXd &centroids, int from, int to, int id, std::vector<int> &triangles)
{
    // no triangle in this node
    if(to <= from)
    {
        std::cout << "scene is empty" << std::endl;
        return -1;
    }

    // If there is only 1 triangle left, then we are at a leaf
    if (to - from <= 1)
    {
        //TODO-didn't do? create leaf node and retun correct left index


        Vector3d a = V.row(F(triangles[from], 0));
        Vector3d b = V.row(F(triangles[from], 1));
        Vector3d c = V.row(F(triangles[from], 2));

        AlignedBox3d tri_box = bbox_from_triangle(a, b, c);

        Node leaf;
        leaf.parent = (id + 1) / 2;
        leaf.triangle = triangles[from];
        leaf.bbox = tri_box;
        leaf.left = -1;
        leaf.right = -1;
        if(nodes.size() <= id)
            nodes.resize(id + 1);

        nodes[id] = leaf;
        return id;
    }

    AlignedBox3d centroid_box;

    //TODO-Done Use AlignedBox3d to find the box around the current centroids    

   for (int i = from; i < to; i++)
   {
        Vector3d a = V.row(F(triangles[i], 0));
        Vector3d b = V.row(F(triangles[i], 1));
        Vector3d c = V.row(F(triangles[i], 2));
        centroid_box.extend(a);
        centroid_box.extend(b);
        centroid_box.extend(c);
   }

    // Diagonal of the box
    Vector3d extent = centroid_box.diagonal();
    //TODO-Done find the largest dimension
    int longest_dim = 0; //x=0, y=1, z=2?
    if(centroid_box.max()(1) - centroid_box.min()(1) > centroid_box.max()(0) - centroid_box.min()(0))
        longest_dim = 1;
    if(centroid_box.max()(2) - centroid_box.min()(2) > centroid_box.max()(longest_dim) - centroid_box.min()(longest_dim))
        longest_dim = 2;    


    // TODO-done sort centroids along the longest dimension
    std::sort(triangles.begin() + from, triangles.begin() + to, [&](int f1, int f2) {
        //TODO-done sort the **triangles** along the centroid largest dimension
        // return true if triangle f1 comes before triangle f2
        
        return centroids(f1, longest_dim) < centroids(f2, longest_dim);
    });

    //TODO-Done Create a new internal node and do a recursive call to build the left and right part of the tree
    //TODO-Done finally return the correct index
    Node child;
    child.parent = (id + 1) / 2;
    child.bbox = centroid_box;
    child.triangle = -1;

    child.left = AABBTree::build_recursive(V, F, centroids, from, (to + from) / 2, (2 * id) + 1, triangles);
    child.right = AABBTree::build_recursive(V, F, centroids, (to + from) / 2, to, 2 * (id + 1), triangles);

    if(nodes.size() <= id)
        nodes.resize(id + 1);
    nodes[id] = child;

    return id;
}

////////////////////////////////////////////////////////////////////////////////
// Intersection code
////////////////////////////////////////////////////////////////////////////////

double ray_triangle_intersection(const Vector3d &ray_origin, const Vector3d &ray_direction, const Vector3d &a, const Vector3d &b, const Vector3d &c, Vector3d &p, Vector3d &N)
{
    // TODO - Done
    // Compute whether the ray intersects the given triangle.
    // If you have done the parallelogram case, this should be very similar to it.
    Vector3d v1v0 = b - a;
    Vector3d v2v0 = c - a;
    Vector3d rov0 = ray_origin - a;
    Vector3d n = v1v0.cross(v2v0);
    Vector3d q = rov0.cross(ray_direction);
    double d = 1 / ray_direction.dot(n);
    double u = d * (-q).dot(v2v0);
    double v = d *    q.dot(v1v0);
    double t = d * (-n).dot(rov0);

    if(t < 0)
    {
        return -1;
    }

    if( u >= 0 && v >= 0 && u + v <= 1)
    {
        p = ray_origin + (t * ray_direction);
        N = v1v0.cross(v2v0).normalized();

        return t;
    }

    return -1;
}

bool ray_box_intersection(const Vector3d &ray_origin, const Vector3d &ray_direction, const AlignedBox3d &box) 
//RETURNS ASSIGNMENT BOOL NOT INT UNLIKE LAST
{
    // TODO-done
    // Compute whether the ray intersects the given box.
    // we are not testing with the real surface here anyway.
    Vector3d bmin = box.min();
    Vector3d bmax = box.max();
    Vector3d inverse(0,0,0);
    double tmax = INFINITY;
    double tmin = -INFINITY;
    for(int i = 0; i < 3; i++)
    {
        inverse[i] = 1 / ray_direction[i];
        double t1 = (bmin[i] - ray_origin[i]) * inverse[i];
        double t2 = (bmax[i] - ray_origin[i]) * inverse[i];

        tmin = std::min(std::max(t1, tmin), std::max(t2, tmin));
        tmax = std::max(std::min(t1, tmax), std::min(t2, tmax));
    }

    return tmin < tmax;
}

double ray_sphere_intersection(const Vector3d &ray_origin, const Vector3d &ray_direction, int index, Vector3d &p, Vector3d &N)
{
    // TODO-done, implement the intersection between the ray and the sphere at index index.
    //return t or -1 if no intersection

    const Vector3d sphere_center = sphere_centers[index];
    const double sphere_radius = sphere_radii[index];
    double t = -1;

    double a = ray_direction.dot(ray_direction);
    double b = 2 * (ray_direction.dot(ray_origin - sphere_center));
    double c = (ray_origin - sphere_center).dot(ray_origin - sphere_center) - pow(sphere_radius, 2);

    double root = b * b - (4 * a * c);

    if (root < 0)
    {
        return -1;
    }
    else
    {
        root = sqrt(root);
        double t = (-b - root) / (2 * a);
        if (t < 0)
            t = (-b + root) / (2 * a);

        p = ray_origin + (t* ray_direction);
        N = (p - sphere_center).normalized();

        return t;
    }

    return -1;
}

double ray_parallelogram_intersection(const Vector3d &ray_origin, const Vector3d &ray_direction, int index, Vector3d &p, Vector3d &N)
{
    // TODO-done, implement the intersection between the ray and the parallelogram at index index.
    //return t or -1 if no intersection

    const Vector3d pgram_origin = parallelograms[index].col(0);
    const Vector3d pgram_u = parallelograms[index].col(1) - pgram_origin;
    const Vector3d pgram_v = parallelograms[index].col(2) - pgram_origin;

    Vector3d v1v0 = pgram_origin + pgram_u - pgram_origin;
    Vector3d v2v0 = pgram_origin + pgram_v - pgram_origin;
    Vector3d rov0 = ray_origin - pgram_origin;
    Vector3d n = v1v0.cross(v2v0);
    Vector3d q = rov0.cross(ray_direction);
    double d = 1 / ray_direction.dot(n);
    double u = d * (-q).dot(v2v0);
    double v = d *    q.dot(v1v0);
    double t = d * (-n).dot(rov0);


    if (t < 0)
    {
        return -1;
    }


    if(u >= 0 && u <= 1 &&
       v >= 0 && v <= 1 &&
       u + v <= 2)
    {
         p = ray_origin + (t * ray_direction); 
        N = (pgram_v.cross(pgram_u)).normalized();
        return t;
    }
    return -1;
}


//Finds the closest intersecting object returns its index
//In case of intersection it writes into p and N (intersection point and normals)
bool find_nearest_object(const Vector3d &ray_origin, const Vector3d &ray_direction, Vector3d &p, Vector3d &N)
{
    bool use_box = true;
    double t = INFINITY;

    // TODO-done
    // Method (1): Traverse every triangle and return the closest hit.
    if(!use_box)
    {
        for (int i = 0; i < facets.rows(); i++)
        {
            Vector3d a = vertices.row(facets(i,0));
            Vector3d b = vertices.row(facets(i,1));
            Vector3d c = vertices.row(facets(i,2));
            Vector3d newP;
            Vector3d newN;

            double newT =ray_triangle_intersection(ray_origin, ray_direction, a, b, c, newP, newN);
            if(newT > 0 && newT <= t)
            {
                t = newT;
                p = newP;
                N = newN;
            }
        }
        N.normalize();
    }
    // Method (2): Traverse the BVH tree and test the intersection with a
    // triangles at the leaf nodes that intersects the input ray.
    // Using a queue to traverse the tree
    else
    {
        std::vector<int> queue;
        queue.push_back(bvh.root);

        int i = 0;
        Vector3d temp_p, temp_N;

        while(i < queue.size())
        {
            
            // ray hit a leaf node
            if(bvh.nodes[queue[i]].triangle >= 0)
            {
                Vector3d a = vertices.row(facets(bvh.nodes[queue[i]].triangle, 0));
                Vector3d b = vertices.row(facets(bvh.nodes[queue[i]].triangle, 1));
                Vector3d c = vertices.row(facets(bvh.nodes[queue[i]].triangle, 2));
                double temp_t = ray_triangle_intersection(ray_origin, ray_direction, a, b, c, temp_p, temp_N);
                if (temp_t >= 0 && temp_t < t)
                {
                    t = temp_t;
                    p = temp_p;
                    N = temp_N.normalized();
                }
                i++;
                continue;
            }

            // does not hit
            if(!ray_box_intersection(ray_origin, ray_direction, bvh.nodes[queue[i]].bbox))
            {
                i++;
                continue;
            }
           
            queue.push_back(2 * (queue[i] + 1));
            queue.push_back((2 * queue[i]) + 1);
            i++;
        }

    }
    //intersection code for bonus marks
    if(bonus)
    {    for(int i=0; i<sphere_centers.size(); i++)
        {
            Vector3d temp_p, temp_N;
            double temp_t = ray_sphere_intersection(ray_origin, ray_direction, i, temp_p, temp_N);
            if(temp_t >= 0 && temp_t < t)
            {
                t = temp_t;
                p = temp_p;
                N = temp_N.normalized();
            }
        }

        for(int i=0; i<parallelograms.size(); i++)
        {
            Vector3d temp_p, temp_N;
            double temp_t = ray_parallelogram_intersection(ray_origin, ray_direction, i, temp_p, temp_N);
            if(temp_t >= 0 && temp_t < t)
            {
                t = temp_t;
                p = temp_p;
                N = temp_N.normalized();
            }
        }
    }

    if(t >= 0 && t != INFINITY)
        return true;

    return false;
}

////////////////////////////////////////////////////////////////////////////////
// Raytracer code
////////////////////////////////////////////////////////////////////////////////

bool is_light_visible(const Vector3d &ray_origin, const Vector3d &ray_direction, const Vector3d &light_position)
{
    Vector3d n, p;
    if(find_nearest_object(ray_origin + (0.0001 * ray_direction), ray_direction, p, n))
        return false;

    return true;
}

Vector4d shoot_ray(const Vector3d &ray_origin, const Vector3d &ray_direction, int max_bounce)
{
    //Intersection point and normal, these are output of find_nearest_object
    Vector3d p, N;

    const bool nearest_object = find_nearest_object(ray_origin, ray_direction, p, N);

    if (!nearest_object)
    {
        // Return a transparent color
        return Vector4d(0, 0, 0, 0);
    }

    // Ambient light contribution
    const Vector4d ambient_color = obj_ambient_color.array() * ambient_light.array();

    // Punctual lights contribution (direct lighting)
    Vector4d lights_color(0, 0, 0, 0);
    for (int i = 0; i < light_positions.size(); ++i)
    {
        const Vector3d &light_position = light_positions[i];
        const Vector4d &light_color = light_colors[i];

        const Vector3d Li = (light_position - p).normalized();


        if(is_light_visible(p, Li, light_position) || (!bonus))
        {
            Vector4d diff_color = obj_diffuse_color;

            // Diffuse contribution
            const Vector3d Li = (light_position - p).normalized();
            const Vector4d diffuse = diff_color * std::max(Li.dot(N), 0.0);

            // Specular contribution
            const Vector3d Hi = (Li - ray_direction).normalized();
            const Vector4d specular = obj_specular_color * std::pow(std::max(N.dot(Hi), 0.0), obj_specular_exponent);

            // Attenuate lights according to the squared distance to the lights
            const Vector3d D = light_position - p;
            lights_color += (diffuse + specular).cwiseProduct(light_color) / D.squaredNorm();
        }
    }

    // Reflections
    Vector4d refl_color = obj_reflection_color;
    Vector4d reflection_color(0, 0, 0, 0);
    if(max_bounce > 0 && bonus)
    {
        
        Vector3d bounce_direction = (ray_direction - (2 * ray_direction.dot(N)) * N).normalized();
        reflection_color += shoot_ray(p + (0.0001 * bounce_direction), bounce_direction, max_bounce - 1);

        for(int i=0; i<4; i++)
            reflection_color[i] *= refl_color[i];
    }

    // Rendering equation
    Vector4d C = ambient_color + lights_color + reflection_color;

    //Set alpha to 1
    C(3) = 1;

    return C;
}

////////////////////////////////////////////////////////////////////////////////

void raytrace_scene()
{
    std::cout << "Simple ray tracer." << std::endl;

    int w = 640; // 640
    int h = 480; // 480
    MatrixXd R = MatrixXd::Zero(w, h);
    MatrixXd G = MatrixXd::Zero(w, h);
    MatrixXd B = MatrixXd::Zero(w, h);
    MatrixXd A = MatrixXd::Zero(w, h); // Store the alpha mask

    // The camera always points in the direction -z
    // The sensor grid is at a distance 'focal_length' from the camera center,
    // and covers an viewing angle given by 'field_of_view'.
    double aspect_ratio = double(w) / double(h);
    //TODO - Done
    double image_y = focal_length * tanf(field_of_view / 2);
    double image_x = focal_length * tanf(field_of_view / 2) * aspect_ratio;

    // The pixel grid through which we shoot rays is at a distance 'focal_length'
    const Vector3d image_origin(-image_x, image_y, camera_position[2] - focal_length);
    const Vector3d x_displacement(2.0 / w * image_x, 0, 0);
    const Vector3d y_displacement(0, -2.0 / h * image_y, 0);

    for (unsigned i = 0; i < w; ++i)
    {
        for (unsigned j = 0; j < h; ++j)
        {
            const Vector3d pixel_center = image_origin + (i + 0.5) * x_displacement + (j + 0.5) * y_displacement;

            // Prepare the ray
            Vector3d ray_origin;
            Vector3d ray_direction;

            if (is_perspective)
            {
                // Perspective camera
                ray_origin = camera_position;
                ray_direction = (pixel_center - camera_position).normalized();
            }
            else
            {
                // Orthographic camera
                ray_origin = pixel_center;
                ray_direction = Vector3d(0, 0, -1);
            }

            const Vector4d C = shoot_ray(ray_origin, ray_direction, max_bounce);
            R(i, j) = C(0);
            G(i, j) = C(1);
            B(i, j) = C(2);
            A(i, j) = C(3);
        }
    }

    // Save to png
    write_matrix_to_png(R, G, B, A, filename);
}

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    setup_scene();

    raytrace_scene();
    return 0;
}

