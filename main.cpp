// Bohdan Petrov K13
// lab 3
// var 4

#include "geometry.h"
#include "quad.h"
#include "ray.h"
#include <iostream>
#include <cmath>
#include <algorithm>

int main(){
    double x1,y1,x2,y2,x3,y3,x4,y4;
    double x1R, y1R, x2R, y2R;
    geometry::quad::read_quad(x1,y1,x2,y2,x3,y3,x4,y4);
    geometry::read_point(x1,y1);
    geometry::read_point(x2,y2);
    std::cout << y1 - y2 << " " << x2 - x1 << " " << -y1*(x2 - x1) - x1*(y1 - y2) << '\n';
    //geometry::quad::read_quad(x1,y1,x2,y2,x3,y3,x4,y4);
    geometry::ray::read_ray(x1R, y1R, x2R, y2R);
    std::cout << geometry::intersect_segment_ray(x1R,y1R,x2R,y2R,x1,y1,x2,y2) << '\n';
    // if(geometry::exercise(x1,y1,x2,y2,x3,y3,x4,y4,x1R, y1R, x2R, y2R))
    // std::cout << "Yes" << '\n';
    // else std::cout << "NO" << '\n';
    return 0;
}
