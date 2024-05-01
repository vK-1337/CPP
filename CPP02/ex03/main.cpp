#include "Point.hpp"

float computeArea(Point a, Point b, Point c);
bool bsp( Point const a, Point const b, Point const c, Point const point);

int main(int ac, char **av)
{
    Point A(-3.14, 1.73);
    Point B(-1.82, 5.35);
    Point C(1.1, 1.65);
    Point point(-1.46, 2.77);
    Point point2(2.3, 5.11);

    bool result  = bsp(A, B, C, point);

    std::cout << (result == 1 ? "Oui" : "Non") << std::endl;

    result  = bsp(A, B, C, point2);

    std::cout << (result == 1 ? "Oui" : "Non") << std::endl;

    return (0);
}