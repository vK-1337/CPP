#include "Fixed.hpp"

Fixed::Fixed() : _RawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}
Fixed::Fixed(const Fixed& source)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = source;
    return ;
}

Fixed::~Fixed()
{
	std::cout << "Default desctuctor called" << std::endl;
	return ;
}

int Fixed::getRawBits(void) const
{
	return (this->_RawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->_RawBits = raw;
	return ;
}

Fixed& Fixed::operator=(const Fixed& source)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &source)
        this->_RawBits = source.getRawBits();
    return *this;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_RawBits = value << this->_Fract;
    return ;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_RawBits = roundf(value * (1 << this->_Fract));
    return ;
}

float Fixed::toFloat(void) const
{
    return (float)this->_RawBits / (1 << this->_Fract);
}

int Fixed::toInt(void) const
{
    return this->_RawBits >> this->_Fract;
}

std::ostream& operator<<(std::ostream& os, const Fixed& value){
    return os << value.toFloat();
}