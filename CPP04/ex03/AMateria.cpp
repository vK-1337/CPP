#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
  std::cout << "Default Amateria constructor called" << std::endl;
}


AMateria::~AMateria()
{
  std::cout << "AMateria " << this->_type << " destroyed" << std::endl;
}
AMateria::AMateria(std::string const & type)
{
  this->_type = type;
}

AMateria::AMateria(const AMateria &rhs)
{
  *this = rhs;
  std::cout << "AMateria copy constructor called" << std::endl;
  return;
}
AMateria &AMateria::operator=(const AMateria& rhs)
{
  if (this != &rhs)
  {
  this->_type = rhs._type;
  }
  std::cout << "AMateria " << this->_type << " has been copied with copy assignement operator." << std::endl;
  return *this;
}

std::string const &AMateria::getType() const
{
  return (this->_type);
} //Returns the materia type


AMateria* AMateria::clone() const
{
  return (AMateria*)this;
}

void AMateria::use(ICharacter& target)
{
  std::cout << "AMateria " << this->_type << " has been used on " << target << std::endl;
  return;
}
