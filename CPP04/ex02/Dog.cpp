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
    delete this->_brain;
	std::cout << "A Dog has been destroyed" << std::endl;
	return ;
}

void Dog::makeSound() const
{
	std::cout << "The dog barks : \"WOOF WOOF\"" << std::endl;
	return ;
}

Dog& Dog::operator=( const Dog& rhs ) {
    if (this != &rhs)
    {
        this->_type = rhs._type;
        this->_brain = new Brain( *rhs._brain );
    }
    std::cout << "Animal " << this->_type << " has been copied with copy assignement operator." << std::endl;
    return *this;
}

Dog::Dog(const Dog &rhs)
{
    this->_brain = new Brain();
    *this = rhs;
    std::cout << "Dog copy constructor called" << std::endl;
    return;
}