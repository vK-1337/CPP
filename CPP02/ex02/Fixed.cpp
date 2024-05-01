#include "Fixed.hpp"

Fixed::Fixed() : _RawBits(0)
{
	std::cout << "Fixed Default constructor called" << std::endl;
	return ;
}
Fixed::Fixed(const Fixed& source)
{
    std::cout << "Fixed Copy constructor called" << std::endl;
    *this = source;
    return ;
}

Fixed::~Fixed()
{
	std::cout << "Fixed Default destructor called" << std::endl;
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
    std::cout << "Fixed Copy assignment operator called" << std::endl;
    if (this != &source)
        this->_RawBits = source.getRawBits();
    return *this;
}

Fixed::Fixed(const int value)
{
    std::cout << "Fixed Int constructor called" << std::endl;
    this->_RawBits = value << this->_Fract;
    return ;
}

Fixed::Fixed(const float value)
{
    std::cout << "Fixed Float constructor called" << std::endl;
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

bool Fixed::operator>(const Fixed fixed)
{
    return (this->getRawBits() > fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed fixed)
{
    return (this->getRawBits() >= fixed.getRawBits());
}

bool Fixed::operator<(const Fixed fixed)
{
    return (this->getRawBits() < fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed fixed)
{
    return (this->getRawBits() <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed fixed)
{
    return (this->getRawBits() == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed fixed)
{
    return (this->getRawBits() != fixed.getRawBits());
}

Fixed   Fixed::operator+( const Fixed &rhs ) const {
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed   Fixed::operator-( const Fixed &rhs ) const {
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed   Fixed::operator*( const Fixed &rhs ) const {
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed   Fixed::operator/( const Fixed &rhs ) const {
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed&   Fixed::operator++(void) {
    ++this->_RawBits;
    return *this;
}

Fixed   Fixed::operator++(int) {
    Fixed tmp(*this);
    tmp._RawBits = this->_RawBits++;
    return tmp;
}

Fixed& Fixed::operator--(void) {
    --this->_RawBits;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    tmp._RawBits = this->_RawBits--;
    return tmp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}