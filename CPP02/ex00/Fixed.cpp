#include "Fixed.hpp"

Fixed::Fixed() : _RawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}
Fixed::Fixed(const Fixed& source)
{
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(source.getRawBits());
    return ;
}

Fixed::~Fixed()
{
	std::cout << "Default desctuctor called" << std::endl;
	return ;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
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