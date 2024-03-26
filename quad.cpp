#include "quad.h"
#include "geometry.h"
#include <iostream>

namespace geometry::quad{
    bool read_quad(double &x1, double &y1,double &x2, double &y2,double &x3, double &y3,double &x4, double &y4)
    {
        std::cout << "Enter 1 point:" << '\n';
        multiple_read(x1,y1);
        std::cout << "Enter 2 point:" << '\n';
        multiple_read(x2,y2);
        std::cout << "Enter 3 point:" << '\n';
        multiple_read(x3,y3);
        std::cout << "Enter 4 point:" << '\n';
        multiple_read(x4,y4);
        if(!point_on_line(x1,y1,x2,y2,x3,y3) || !point_on_line(x1,y1,x2,y2,x4,y4) || !point_on_line(x1,y1,x4,y4,x2,y2) || !point_on_line(x1,y1,x4,y4,x3,y3)
        || !point_on_line(x3,y3,x4,y4,x1,y1) || !point_on_line(x3,y3,x4,y4,x2,y2) || !point_on_line(x3,y3,x2,y2,x1,y1) || !point_on_line(x3,y3,x2,y2,x4,y4))
        {
            std::cout << "Wrong input. It's not a quad. Try again" << '\n';
            return 0;
        }
        if(intersect_segment_segment(x1,y1,x2,y2,x3,y3,x4,y4) || intersect_segment_segment(x2,y2,x3,y3,x4,y4,x1,y1))
        {
            std::cout << "Wrong input. It's not a quad1. Try again" << '\n';
            return 0;
        }
        return 1;

    }

    bool multiple_read_quad(double &x1, double &y1,double &x2, double &y2,double &x3, double &y3,double &x4, double &y4)
    {
        std::cout << "Enter points for quad" << '\n';
        while(!(read_quad(x1,y1,x2,y2,x3,y3,x4,y4)));
    }
}