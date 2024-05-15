#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "header.hpp"

std::vector<AMateria *> trash_floor;

class Character : public ICharacter
{
  private:
    std::string _name;
    AMateria *_inventory[4];

  public:
    Character(std::string const &name);
    ~Character();
    Character(const Character &rhs);
    Character &operator=(const Character& rhs);
    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif
