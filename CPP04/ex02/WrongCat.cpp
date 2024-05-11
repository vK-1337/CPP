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