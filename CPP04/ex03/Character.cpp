#include "Character.hpp"
#include <vector>

Character::Character(std::string const &name) : _name(name)
{
    for (int i = 0; i < 4; i++) {
        this->_inventory[i] = NULL;
    }
    std::cout << "A Character has been created" << std::endl;
}
Character::~Character()
{
  for ( int i = 0; i < 4 ; i++)
  {
    if (this->_inventory[i])
      delete this->_inventory[i];
  }
  std::cout << "A Character has been destructed" << std::endl;
}

Character &Character::operator=(const Character& rhs)
{
   if (this != &rhs)
  {
    for (int i = 0; i < 4; i++)
    {
        if (rhs._inventory[i])
            this->_inventory[i] = rhs._inventory[i]->clone();
    }
    this->_name = rhs._name;
  }
  std::cout << "Character " << this->_name << " has been copied with copy assignement operator." << std::endl;
  return *this;
}

Character::Character(const Character &rhs)
{
  *this = rhs;
  std::cout << "Character copy constructor called" << std::endl;
  return;
}

std::string const & Character::getName() const
{
  return this->_name;
}

void Character::equip(AMateria* m)
{
    if (m == NULL)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] == NULL)
        {
            // for (auto it = trash_floor.begin(); it != trash_floor.end(); ++it) {
            // if (*it == m) {
            //         *it = NULL;
            //         break;
            //     }
            // }
            this->_inventory[i] = m;
            std::cout << m->getType() << " materia is now equipped in slot number " << i + 1 << std::endl;
            return;
        }
    }
    std::cout <<  this->getName() << "'s inventory is full!" << std::endl;
}
void Character::unequip(int idx)
{
  if (idx > 3 || idx < 0 || !_inventory[idx])
  {
    std::cout << "Can't unequip this item" << std::endl;
    return;
  }
  _inventory[idx] = NULL;
  return;
}
void Character::use(int idx, ICharacter& target)
{
  if (idx > 3 || idx < 0 || !this->_inventory[idx])
  {
    std::cout << "Can't use this item" << std::endl;
    return;
  }
  _inventory[idx]->use(target);
  return;
}

AMateria *Character::getMateriaAdress(int idx)
{
    if (idx > 3 || idx < 0 || !_inventory[idx])
  {
    std::cout << "Can't get this item's address" << std::endl;
    return NULL;
  }
  return this->_inventory[idx];
}


std::ostream& operator<<(std::ostream& os, const ICharacter& character){
    return os << character.getName();
}
