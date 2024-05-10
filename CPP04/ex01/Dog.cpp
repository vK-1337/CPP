#include "Dog.hpp"

Dog::Dog()
{
    this->_brain = new Brain();
	this->_type = "Dog";
	std::cout << "A Dog has been created" << std::endl;
	return ;
}

Dog::~Dog()
{
    delete(this->_brain);
	std::cout << "A Dog has been destroyed" << std::endl;
	return ;
}

void Dog::makeSound() const
{
	std::cout << "The dog barks : \"WOOF WOOF\"" << std::endl;
	return ;
}