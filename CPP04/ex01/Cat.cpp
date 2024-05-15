#include "Cat.hpp"

Cat::Cat()
{
    this->_brain = new Brain();
    std::cout << "A Cat has been created" << std::endl;
    this->_type = "Cat";
    return;
}

Cat::~Cat()
{
    delete this->_brain;
    std::cout << "A Cat has been destroyed" << std::endl;
    return;
}

void Cat::makeSound() const
{
	std::cout << "The Cat meow : \"Meooooooow\"" << std::endl;
	return ;
}

Cat& Cat::operator=( const Cat& rhs ) {
    if (this != &rhs)
    {
        this->_type = rhs._type;
        this->_brain = new Brain( *rhs._brain );
    }
    std::cout << "Animal " << this->_type << " has been copied with copy assignement operator." << std::endl;
    return *this;
}