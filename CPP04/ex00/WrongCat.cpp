#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->_type = "WrongCat";
    std::cout << "A WrongCat has been created" << std::endl;
    return;
}

WrongCat::~WrongCat()
{
    std::cout << "A WrongCat has been destroyed" << std::endl;
    return;
}

void WrongCat::makeSound() const
{
	std::cout << "The WrongCat meow : \"YEEEEEEEHAAAAAAAA\"" << std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat &rhs)
{
    *this = rhs;
    std::cout << "WrongCat copy constructor called" << std::endl;
    return;
}

WrongCat& WrongCat::operator=( const WrongCat& rhs ) {
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    std::cout << "Animal " << this->_type << " has been copied with copy assignement operator." << std::endl;
    return *this;
}