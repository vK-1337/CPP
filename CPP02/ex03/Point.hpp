#include "Fixed.hpp"

class Point
{
    private:
        const Fixed _x;
        const Fixed _y;

    public:
        Point();
        Point(const float x, const float y);
        ~Point();
        Point &operator=(const Point &source);
        Point(const Point &source);

        Fixed getX( void ) const ;
        Fixed getY( void ) const ;
};