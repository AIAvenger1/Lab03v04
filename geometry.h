#pragma once

namespace geometry{
    bool read_point(double &x, double &y);
    void multiple_read(double &x, double &y);
    bool point_on_line(double x1,double y1,double x2,double y2,double x3,double y3);
    bool point_between(double a, double b, double point);
    bool point_on_ray(double a, double b, double point);
    bool projection_intersect(double Ray1, double Ray2, double Seg1, double Seg2);
    bool intersect(double a, double b, double c, double d);
    bool intersect_segment_ray(double x1, double y1,double x2, double y2,double x3, double y3,double x4, double y4);
    bool intersect_segment_segment(double x1, double y1, double x2, double y2,double x3, double y3,double x4, double y4);
    bool exercise(double x1, double y1,double x2, double y2,double x3, double y3,double x4, double y4, double x1R, double y1R, double x2R, double y2R);
}
