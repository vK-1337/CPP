#include "Ice.hpp"

Ice::Ice()
{
    this->_type = "ice";
    std::cout << "An ice materia has been created!" << std::endl ;
}
Ice::~Ice()
{
    std::cout << "An ice materia has been destructed!" << std::endl;
}
Ice::Ice(const Ice &rhs)
{
    *this = rhs;
    std::cout << "Ice copy constructor called" << std::endl;
    return;
}
Ice &Ice::operator=(const Ice& rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    std::cout << "AMateria " << this->_type << " has been copied with copy assignement operator." << std::endl;
    return *this;
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an icebolt at " << target << " *" << std::endl;
    return;
}

AMateria* Ice::clone() const
{
    return new Ice(*this);
}
