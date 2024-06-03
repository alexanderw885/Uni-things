////////////////////////////////////////////////////////////////////////////////
#include <algorithm>
#include <complex>
#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>

#include <Eigen/Dense>
// Shortcut to avoid  everywhere, DO NOT USE IN .h
using namespace Eigen;
////////////////////////////////////////////////////////////////////////////////

const std::string root_path = DATA_DIR;

// Computes the determinant of the matrix whose columns are the vector u and v
double inline det(const Vector2d &u, const Vector2d &v)
{
    return (u[0] * v[1]) - (u[1] * v[0]);
}

// Return true iff [a,b] intersects [c,d]
bool intersect_segment(const Vector2d &a, const Vector2d &b, const Vector2d &c, const Vector2d &d)
{
    Vector2d line1(a.x() - b.x(), a.y() - b.y());
    Vector2d comp1(a.x() - c.x(), a.y() - c.y());
    Vector2d comp2(a.x() - d.x(), a.y() - d.y());
    if (det(line1, comp1) * det(line1, comp2) < 0)
    {
        Vector2d line2(c.x() - d.x(), c.y() - d.y());
        Vector2d comp1(c.x() - a.x(), c.y() - a.y());
        Vector2d comp2(c.x() - b.x(), c.y() - b.y());
        if (det(line2, comp1) * det(line2, comp2) < 0)
        {
            return true;
        }
            
    }

    return false;
}

////////////////////////////////////////////////////////////////////////////////

bool is_inside(const std::vector<Vector2d> &poly, const Vector2d &query)
{
    // 1. Compute bounding box and set coordinate of a point outside the polygon
    double x = poly[0].x();
    double y = poly[0].y();
    for (int i = 1; i < poly.size(); i++)
    {
        x = std::max(x, poly[i].x());
        y = std::max(y, poly[i].y());
    }
    Vector2d outside(x+1, y+1);

    // 2. Cast a ray from the query point to the 'outside' point, count number of intersections
    int intersects = 0;
    for (int i = 0; i < poly.size(); i++) 
    {
        bool hit;
        // Modulus is to catch where final point connects to first point
        hit = intersect_segment(query, outside, poly[i], poly[(i + 1) % poly.size()]);
        if (hit)
        {
            intersects++;
        }
    }
    if (intersects % 2 == 0)
    {
        return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////

std::vector<Vector2d> load_xyz(const std::string &filename)
{
    std::vector<Vector2d> points;
    std::ifstream in(filename);
    std::string line;
    

    getline(in, line); // First line is number of points
    while (getline(in, line)) 
    {
        std::stringstream stream(line);
        std::string value;
        Vector2d vect;

        int dimcount = 0;
        while (getline(stream, value, ' '))
        {
            if (dimcount >= 2)
            {
                break;
            }
            else
            {
                vect[dimcount] = std::stod(value);
                dimcount++;
            }
        }
        points.push_back(vect);
    }
    return points;
}

void save_xyz(const std::string &filename, const std::vector<Vector2d> &points)
{
    // Make string of all points in the polygon
    std::string out = "";
    out += std::to_string(points.size())+ "\n";
    for (int i = 0; i < points.size(); i++)
    {
        out += std::to_string(points[i].x()) + " " + std::to_string(points[i].y()) + " 0\n";
    }

    // Save string to file
    std::ofstream fileOut(root_path+filename);
    fileOut << out;
    fileOut.close();
    // TODO
}

std::vector<Vector2d> load_obj(const std::string &filename)
{
    std::ifstream in(filename);
    std::vector<Vector2d> points;
    std::vector<Vector2d> poly;
    char key;
    while (in >> key)
    {
        if (key == 'v')
        {
            double x, y, z;
            in >> x >> y >> z;
            points.push_back(Vector2d(x, y));
        }
        else if (key == 'f')
        {
            std::string line;
            std::getline(in, line);
            std::istringstream ss(line);
            int id;
            while (ss >> id)
            {
                poly.push_back(points[id - 1]);
            }
        }
    }
    return poly;
}


////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    const std::string points_path = root_path + "/points.xyz";
    const std::string poly_path = root_path + "/polygon.obj";


    std::vector<Vector2d> points = load_xyz(points_path);
    ////////////////////////////////////////////////////////////////////////////////
    //Point in polygon
    std::vector<Vector2d> poly = load_obj(poly_path);
    std::vector<Vector2d> result;
    for (size_t i = 0; i < points.size(); ++i)
    {
        if (is_inside(poly, points[i]))
        {
            result.push_back(points[i]);
        }
    }
    save_xyz("output.xyz", result);

    return 0;
}
