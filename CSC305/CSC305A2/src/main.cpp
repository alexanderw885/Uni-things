// C++ include
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

// Utilities for the Assignment
#include "utils.h"

// Image writing library
#define STB_IMAGE_WRITE_IMPLEMENTATION // Do not include this line twice in your project!
#include "stb_image_write.h"

// Shortcut to avoid Eigen:: everywhere, DO NOT USE IN .h
using namespace Eigen;

void raytrace_sphere()
{
    std::cout << "Simple ray tracer, one sphere with orthographic projection" << std::endl;

    const std::string filename("sphere_orthographic.png");
    MatrixXd C = MatrixXd::Zero(800, 800); // Store the color
    MatrixXd A = MatrixXd::Zero(800, 800); // Store the alpha mask

    const Vector3d camera_origin(0, 0, 3);
    const Vector3d camera_view_direction(0, 0, -1);

    // The camera is orthographic, pointing in the direction -z and covering the
    // unit square (-1,1) in x and y
    const Vector3d image_origin(-1, 1, 1);
    const Vector3d x_displacement(2.0 / C.cols(), 0, 0);
    const Vector3d y_displacement(0, -2.0 / C.rows(), 0);

    // Single light source
    const Vector3d light_position(-1, 1, 1);

    for (unsigned i = 0; i < C.cols(); ++i)
    {
        for (unsigned j = 0; j < C.rows(); ++j)
        {
            const Vector3d pixel_center = image_origin + double(i) * x_displacement + double(j) * y_displacement;

            // Prepare the ray
            const Vector3d ray_origin = pixel_center;
            const Vector3d ray_direction = camera_view_direction;


            // Intersect with the sphere
            // NOTE: this is a special case of a sphere centered in the origin and for orthographic rays aligned with the z axis
            Vector2d ray_on_xy(ray_origin(0), ray_origin(1));
            const double sphere_radius = 0.9;

            if (ray_on_xy.norm() < sphere_radius)
            {
                // The ray hit the sphere, compute the exact intersection point
                Vector3d ray_intersection(
                    ray_on_xy(0), ray_on_xy(1),
                    sqrt(sphere_radius * sphere_radius - ray_on_xy.squaredNorm()));

                // Compute normal at the intersection point
                Vector3d ray_normal = ray_intersection.normalized();

                // Simple diffuse model
                C(i, j) = (light_position - ray_intersection).normalized().transpose() * ray_normal;

                // Clamp to zero
                C(i, j) = std::max(C(i, j), 0.);

                // Disable the alpha mask for this pixel
                A(i, j) = 1;
            }
        }
    }

    // Save to png
    write_matrix_to_png(C, C, C, A, filename);
}

// calculates t, u, and v for if ray intersects with triangle, where
// t * rd is distance from ro to plane
// u, v can be used to check if ray intersects with triangle
Vector3d triIntersect(Vector3d ro, Vector3d rd, Vector3d v0, Vector3d v1, Vector3d v2)
{
    // algorithm from: https://iquilezles.org/articles/intersectors/
    Vector3d v1v0 = v1 - v0;
    Vector3d v2v0 = v2 - v0;
    Vector3d rov0 = ro - v0;
    Vector3d n = v1v0.cross(v2v0);
    Vector3d q = rov0.cross(rd);
    double d = 1 / rd.dot(n);
    double u = d * (-q).dot(v2v0);
    double v = d *    q.dot(v1v0);
    double t = d * (-n).dot(rov0);

    return Vector3d(t, u, v);
}

void raytrace_parallelogram()
{
    std::cout << "Simple ray tracer, one parallelogram with orthographic projection" << std::endl;

    const std::string filename("plane_orthographic.png");
    MatrixXd C = MatrixXd::Zero(800, 800); // Store the color
    MatrixXd A = MatrixXd::Zero(800, 800); // Store the alpha mask

    const Vector3d camera_origin(0, 0, 3);
    const Vector3d camera_view_direction(0, 0, -1);

    // The camera is orthographic, pointing in the direction -z and covering the unit square (-1,1) in x and y
    const Vector3d image_origin(-1, 1, 1);
    const Vector3d x_displacement(2.0 / C.cols(), 0, 0);
    const Vector3d y_displacement(0, -2.0 / C.rows(), 0);

    // Parameters of the parallelogram (position of the lower-left corner + two sides)
    const Vector3d pgram_origin(-0.5, -0.5, 0);
    const Vector3d pgram_u(0, 0.7, -10);
    const Vector3d pgram_v(1, 0.4, 0);

    // Single light source
    const Vector3d light_position(-1, 1, 1);

    for (unsigned i = 0; i < C.cols(); ++i)
    {
        for (unsigned j = 0; j < C.rows(); ++j)
        {
            const Vector3d pixel_center = image_origin + double(i) * x_displacement + double(j) * y_displacement;

            // Prepare the ray
            const Vector3d ray_origin = pixel_center;
            const Vector3d ray_direction = camera_view_direction;

            // Check if the ray intersects with the parallelogram
            Vector3d pgram_c2 = pgram_origin + pgram_u;
            Vector3d pgram_c3 = pgram_origin + pgram_v;

            Vector3d t_u_v = triIntersect(ray_origin, ray_direction, pgram_origin, pgram_c2, pgram_c3);

            if    (t_u_v[1]>=0 && t_u_v[1] <= 1
                && t_u_v[2]>=0 && t_u_v[2] <= 1
                && t_u_v[1] + t_u_v[2] <=2
                && t_u_v[0] >= 0)
            {
                // The ray hit the parallelogram, compute the exact intersection
                // point
                Vector3d ray_intersection = ray_origin + (t_u_v[0]*ray_direction);

                // Compute normal at the intersection point
                Vector3d ray_normal = pgram_v.cross(pgram_u).normalized();

                // Simple diffuse model
                C(i, j) = (light_position - ray_intersection).normalized().transpose() * ray_normal;

                // Clamp to zero
                C(i, j) = std::max(C(i, j), 0.);

                // Disable the alpha mask for this pixel
                A(i, j) = 1;
            }
        }
    }

    // Save to png
    write_matrix_to_png(C, C, C, A, filename);
}

void raytrace_perspective()
{
    std::cout << "Simple ray tracer, one parallelogram with perspective projection" << std::endl;

    const std::string filename("plane_perspective.png");
    MatrixXd C = MatrixXd::Zero(800, 800); // Store the color
    MatrixXd A = MatrixXd::Zero(800, 800); // Store the alpha mask

    const Vector3d camera_origin(0, 0, 3);
    const Vector3d camera_view_direction(0, 0, -1);

    // The camera is perspective, pointing in the direction -z and covering the unit square (-1,1) in x and y
    const Vector3d image_origin(-1, 1, 1);
    const Vector3d x_displacement(2.0 / C.cols(), 0, 0);
    const Vector3d y_displacement(0, -2.0 / C.rows(), 0);

    // Parameters of the parallelogram (position of the lower-left corner + two sides)
    const Vector3d pgram_origin(-0.5, -0.5, 0);
    const Vector3d pgram_u(0, 0.7, -10);
    const Vector3d pgram_v(1, 0.4, 0);

    // Single light source
    const Vector3d light_position(-1, 1, 1);

    for (unsigned i = 0; i < C.cols(); ++i)
    {
        for (unsigned j = 0; j < C.rows(); ++j)
        {
            const Vector3d pixel_center = image_origin + double(i) * x_displacement + double(j) * y_displacement;

            // Prepare the ray (origin point and direction)
            const Vector3d ray_origin = camera_origin;
            const Vector3d ray_direction = pixel_center - camera_origin;

            // Check if the ray intersects with the parallelogram
            Vector3d pgram_c2 = pgram_origin + pgram_u;
            Vector3d pgram_c3 = pgram_origin + pgram_v;
            Vector3d t_u_v = triIntersect(ray_origin, ray_direction, pgram_origin, pgram_c2, pgram_c3);
            
            if (t_u_v[1] >= 0 && t_u_v[1] <= 1
                && t_u_v[2] >= 0 && t_u_v[2] <= 1
                && t_u_v[1] + t_u_v[2] <= 2
                && t_u_v[0] >= 0)
            {
                // The ray hit the parallelogram, compute the exact intersection
                // point
                Vector3d ray_intersection = ray_origin + (t_u_v[0] * ray_direction);

                // Compute normal at the intersection point
                Vector3d ray_normal = pgram_v.cross(pgram_u).normalized();

                // Simple diffuse model
                C(i, j) = (light_position - ray_intersection).normalized().transpose() * ray_normal;

                // Clamp to zero
                C(i, j) = std::max(C(i, j), 0.);

                // Disable the alpha mask for this pixel
                A(i, j) = 1;
            }
        }
    }

    // Save to png
    write_matrix_to_png(C, C, C, A, filename);
}

void raytrace_shading()
{
    std::cout << "Simple ray tracer, one sphere with different shading" << std::endl;

    const std::string filename("shading.png");
    const int size = 800; // For easy changing
    MatrixXd R = MatrixXd::Zero(size, size); // Store the color red
    MatrixXd G = MatrixXd::Zero(size, size); // Store the color green
    MatrixXd B = MatrixXd::Zero(size, size); // Store the color blue
    MatrixXd A = MatrixXd::Zero(size, size); // Store the alpha mask

    const Vector3d camera_origin(0, 0, 3);
    const Vector3d camera_view_direction(0, 0, -1);

    // The camera is perspective, pointing in the direction -z and covering the unit square (-1,1) in x and y
    const Vector3d image_origin(-1, 1, 1);
    const Vector3d x_displacement(2.0 / A.cols(), 0, 0);
    const Vector3d y_displacement(0, -2.0 / A.rows(), 0);

    //Sphere setup
    const Vector3d sphere_center(0, 0, 0);
    const double sphere_radius = 0.9;

    //material params
    const Vector3d diffuse_color(1, 0, 1);
    const double specular_exponent = 100;
    const Vector3d specular_color(0., 0, 1);

    // Single light source
    const Vector3d light_position(-1, 1, 1);
    double ambient = 0.1;

    for (unsigned i = 0; i < A.cols(); ++i)
    {
        for (unsigned j = 0; j < A.rows(); ++j)
        {
            const Vector3d pixel_center = image_origin + double(i) * x_displacement + double(j) * y_displacement;

            // TODO: Prepare the ray (origin point and direction)
            const Vector3d ray_origin = camera_origin;
            const Vector3d ray_direction = pixel_center - camera_origin;
            
            // Intersect with the sphere
            double a = ray_direction.dot(ray_direction);
            double b = 2 * (ray_direction.dot(ray_origin-sphere_center));
            double c = (ray_origin - sphere_center).dot(ray_origin - sphere_center) - pow(sphere_radius, 2);
            
            //use to solve quadratic equation
            double root = b * b - (4 * a * c);

            if (root >= 0)
            {
                // Making sure t is smallest value greater than 0
                root = sqrt(root);
                double t = (-b - root) / (2 * a);
                if (t < 0)
                {
                    t = (-b + root) / (2 * a);
                    if (t < 0)
                        continue;
                }


                // TODO: The ray hit the sphere, compute the exact intersection point
                Vector3d ray_intersection = ray_origin + (t * ray_direction);
                
                // TODO: Compute normal at the intersection point
                Vector3d ray_normal = (ray_intersection - sphere_center).normalized();


                // TODO: Add shading parameter here
                Vector3d l = (light_position - ray_intersection).normalized();
                Vector3d v = (camera_origin - ray_intersection).normalized();
                Vector3d n = ray_normal;

                const double diffuse = std::max(n.dot(l), 0.0);

                Vector3d h = (v + l).normalized();
                const double specular = std::max(std::pow(n.dot(h), specular_exponent), 0.0);

                // Simple diffuse model
                R(i, j) = ambient + (diffuse * diffuse_color[0]) + (specular * specular_color[0]);
                G(i, j) = ambient + (diffuse * diffuse_color[1]) + (specular * specular_color[1]);
                B(i, j) = ambient + (diffuse * diffuse_color[2]) + (specular * specular_color[2]);
                
                // Clamp to zero
                
                R(i, j) = std::max(R(i, j), 0.);
                G(i, j) = std::max(G(i, j), 0.);
                B(i, j) = std::max(B(i, j), 0.);


                // Disable the alpha mask for this pixel
                A(i, j) = 1;
            }
        }
    }

    // Save to png
    write_matrix_to_png(R, G, B, A, filename);
}

int main()
{
    //raytrace_sphere();
    //raytrace_parallelogram();
    //raytrace_perspective();
    raytrace_shading();

    return 0;
}
