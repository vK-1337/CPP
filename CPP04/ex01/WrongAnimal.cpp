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