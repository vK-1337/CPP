#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "A WrongAnimal has been created" << std::endl;
    return;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "A WrongAnimal has been destroyed" << std::endl;
    return;
}
std::string WrongAnimal::getType() const
{
    return (this->_type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal makes a generic sound" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &rhs)
{
    *this = rhs;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    return;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& rhs ) {
    if (this != &rhs)
    {
    this->_type = rhs._type;
    }
    std::cout << "WrongAnimal " << this->_type << " has been copied with copy assignement operator." << std::endl;
    return *this;
}