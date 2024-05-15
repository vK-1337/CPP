#include "Cat.hpp"

Cat::Cat()
{
    this->_type = "Cat";
    std::cout << "A Cat has been created" << std::endl;
    return;
}

Cat::~Cat()
{
    std::cout << "A Cat has been destroyed" << std::endl;
    return;
}

void Cat::makeSound() const
{
	std::cout << "The Cat meow : \"Meooooooow\"" << std::endl;
	return ;
}

Cat::Cat(const Cat &rhs)
{
    *this = rhs;
    std::cout << "Cat copy constructor called" << std::endl;
    return;
}

Cat& Cat::operator=( const Cat& rhs ) {
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    std::cout << "Animal " << this->_type << " has been copied with copy assignement operator." << std::endl;
    return *this;
}

