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
    geometry::quad::multiple_read_quad(x1,y1,x2,y2,x3,y3,x4,y4);
    geometry::ray::multiple_read_ray(x1R, y1R, x2R, y2R);
     if(geometry::exercise(x1,y1,x2,y2,x3,y3,x4,y4,x1R, y1R, x2R, y2R))
     std::cout << "Yes" << '\n';
     else std::cout << "NO" << '\n';
     return 0;
}
