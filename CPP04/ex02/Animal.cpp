#include "Animal.hpp"

AAnimal::AAnimal()
{
    std::cout << "An Animal has been created" << std::endl;
    return;
}

AAnimal::~AAnimal()
{
    std::cout << "An Animal has been destroyed" << std::endl;
    return;
}
std::string AAnimal::getType() const
{
    return (this->_type);
}

void AAnimal::makeSound() const
{
    std::cout << "Animal makes a generic sound" << std::endl;
}

AAnimal::AAnimal(const AAnimal &rhs)
{
    *this = rhs;
    std::cout << "Animal copy constructor called" << std::endl;
    return;
}

AAnimal& AAnimal::operator=( const AAnimal& rhs ) {
    if (this != &rhs)
    {
    this->_type = rhs._type;
    }
    std::cout << "Animal " << this->_type << " has been copied with copy assignement operator." << std::endl;
    return *this;
}