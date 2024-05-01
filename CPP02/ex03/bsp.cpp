#include "Point.hpp"
#include <cmath>

float computeArea(Point a, Point b, Point c)
{

    float x1, y1;
    float x2, y2;
    float x3, y3;

    x1 = a.getX().toFloat();
    y1 = a.getY().toFloat();
    x2 = b.getX().toFloat();
    y2 = b.getY().toFloat();
    x3 = c.getX().toFloat();
    y3 = c.getY().toFloat();

    return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    double triangle_area;
    double area1;
    double area2;
    double area3;

    triangle_area = computeArea(a, b, c);
    area1 = computeArea(a, b, point);
    area2 = computeArea(a, c, point);
    area3 = computeArea(c, b, point);

    if (area1 == 0 || area2 == 0 || area3 == 0 || triangle_area == 0)
        return 0;
    if (area1 + area2 + area3 == triangle_area)
        return 1;
    return (0);
}
