#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
    std::cout << "Point d   efault constructor called" << std::endl;
    return;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
    std::cout << "Point constructor with parameters called" << std::endl;
    return;
}

Point::~Point()
{
    std::cout << "Point default destructor called" << std::endl;
    return;
}

Point::Point(const Point& source) : _x(source.getX()), _y(source.getY())
{
    std::cout << "Point Copy constructor called" << std::endl;
    *this = source;
    return ;
}

Point& Point::operator=(const Point& source)
{
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Fixed Point::getX( void ) const
{
    return this->_x;
}

Fixed Point::getY( void ) const
{
    return this->_y;
}
