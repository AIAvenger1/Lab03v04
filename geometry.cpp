#include "geometry.h"
#include "math.h"
#include <iostream>
#include <cmath>

const double EPS = 1E-9;

namespace geometry{

    bool read_point(double &x, double &y){
        std::cin >> x >> y;
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(80, '\n');
            std::cout << "Wrong input. Try again." <<  std::endl;
            return 0;
        }
        return 1;
    }

    void multiple_read(double &x, double &y){
        std::cout << "Enter point as x y:" << '\n';
        while(!(read_point(x,y)));
    }

    bool point_on_line(double x1,double y1,double x2,double y2,double x3,double y3)
    {
        double A = (y1-y2), B = (x2 - x1), C = -y1*B - x1*A;
        return A*x3 + B*y3 + C;
    }


    bool point_between(double a, double b, double point){
        return std::min(a,b) <= point + EPS && point <= std::max(a,b) + EPS;
    }
    bool point_on_ray(double a, double b, double point){
        if(b>a) return point + EPS >= a;
        if(b<a) return point +EPS <= a;
    }
    bool projection_intersect(double Ray1, double Ray2, double Seg1, double Seg2){
        if(Ray1 < Ray2) return Ray1 < std::max(Seg2,Seg1);
        else if(Ray1 > Ray2) return std::min(Seg1,Seg2) < Ray1;
    }
    bool intersect(double a, double b, double c, double d)
    {
        if(a > b) std::swap(a,b);
        if(c > d) std::swap(c,d);
        return std::max(a,c) <= std::min(b,d);
    }

       bool intersect_segment_ray(double x1R, double y1R,double x2R, double y2R,double x1, double y1,double x2, double y2)
    {
        double A1 = (y1R-y2R), B1 = (x2R-x1R), C1 = -y1R*B1 - x1R*A1;
        double A2 = (y1-y2), B2 = (x2 - x1), C2 = -y1*B2 - x1*A2;
        std::cout << A2 << " " << B2 << " " << C2 << '\n';
        double denom = math::det(A1,B1,A2,B2);
        std::cout << denom << std::endl;
        if(denom != 0)
        {
            double x = - math::det(C1, B1, C2, B2)/ denom;
            //std::cout << x << '\n';
            double y = - math::det(A1, C1, A2, C2)/ denom;
            //std::cout << y << '\n';
            //std::cout << point_between(x1,x2,x) << " " << point_between(y1,y2,y) << " " << point_on_ray(x1,x2,x) << " " << point_on_ray(y1,y2,y) << '\n';
            return point_between(x1,x2,x) && point_between(y1,y2,y) && point_on_ray(x1R,x2R,x) && point_on_ray(y1R,y2R,y);
        }
        else
            return math::det(A1, C1, A2, C2) == 0 && math::det(A1, C1, A2, C2) == 0 && intersect(x1R,x2R,x1,x2) && projection_intersect(y1R,y2R,y1,y2);
    }

   bool intersect_segment_segment(double x1, double y1, double x2, double y2,double x3, double y3,double x4, double y4)
    {
        double A1 = (y1-y2), B1 = (x2-x1), C1 = -y1*B1 - x1*A1;
        double A2 = (y3-y4), B2 = (x4 - x3), C2 = -y3*B2 - x3*A2;
        std::cout << A2 << " " << B2 << " " << C2 << '\n';
        double denom = math::det(A1,B1,A2,B2);
        std::cout << denom << std::endl;
        if(denom != 0)
        {
            double x = - math::det(C1, B1, C2, B2)/ denom;
            //std::cout << x << '\n';
            double y = - math::det(A1, C1, A2, C2)/ denom;
            //std::cout << y << '\n';
            //std::cout << point_between(x1,x2,x) << " " << point_between(y1,y2,y) << " " << point_on_ray(x1,x2,x) << " " << point_on_ray(y1,y2,y) << '\n';
            return point_between(x1,x2,x) && point_between(y1,y2,y) && point_between(y3,y4,y) && point_between(x3,x4,x);
        }
        else
            return math::det(A1, C1, A2, C2) == 0 && math::det(A1, C1, A2, C2) == 0 && intersect(x1,x2,x3,x4) && intersect(y1,y2,y3,y4);
    }


    bool exercise(double x1, double y1,double x2, double y2,double x3, double y3,double x4, double y4, double x1R, double y1R, double x2R, double y2R)
    {
        if(intersect_segment_ray(x1R,y1R,x2R,y2R, x1, y1, x2, y2) || intersect_segment_ray(x1R,y1R,x2R,y2R, x2, y2, x3, y3)
        || intersect_segment_ray(x1R,y1R,x2R,y2R, x4, y4, x1, y1) || intersect_segment_ray(x1R,y1R,x2R,y2R, x3, y3, x4, y4))
        return 1;
        else return 0;
    }

    
}