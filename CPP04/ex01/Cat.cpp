#include "Cat.hpp"

Cat::Cat()
{
    this->_brain = new Brain();
    this->_type = "Cat";
    std::cout << "A Cat has been created" << std::endl;
    return;
}

Cat::~Cat()
{
    delete(this->_brain);
    std::cout << "A Cat has been destroyed" << std::endl;
    return;
}

void Cat::makeSound() const
{
	std::cout << "The Cat meow : \"Meooooooow\"" << std::endl;
	return ;
}