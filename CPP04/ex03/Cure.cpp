#include "Cure.hpp"

Cure::Cure()
{
  std::cout << "A cure materia has been created!" << std::endl ;
}
Cure::~Cure()
{
  std::cout << "A cure materia has been destructed!" << std::endl;
}
Cure::Cure(const Cure &rhs)
{
  *this = rhs;
}
Cure &Cure::operator=(const Cure& rhs)
{
  if (this != &rhs)
  {
  this->_type = rhs._type;
  }
  std::cout << "AMateria " << this->_type << " has been copied with copy assignement operator." << std::endl;
  return *this;
}

void Cure::use(ICharacter& target)
{
  std::cout << "* heals " << target << "'s wounds *" << std::endl;
  return;
}
