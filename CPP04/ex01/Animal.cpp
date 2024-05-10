#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "An Animal has been created" << std::endl;
    return;
}

Animal::~Animal()
{
    std::cout << "An Animal has been destroyed" << std::endl;
    return;
}
std::string Animal::getType() const
{
    return (this->_type);
}

void Animal::makeSound() const
{
    std::cout << "Animal makes a generic sound" << std::endl;
}

Animal::Animal(const Animal &rhs)
{
    *this = rhs;
    std::cout << "Animal copy constructor called" << std::endl;
    return;
}

Animal&   Animal::operator=( const Animal& rhs ) {
    this->_type = rhs._type;
    std::cout << "Animal " << this->_type << " has been copied with copy assignement operator." << std::endl;
    return *this;
}