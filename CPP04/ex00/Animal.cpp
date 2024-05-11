#include "Animal.hpp"

Animal::Animal() : _type("Animal")
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
