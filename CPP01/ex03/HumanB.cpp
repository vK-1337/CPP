#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name)
{
    this->_weapon = NULL;
    return ;
}

HumanB::~HumanB()
{
    return ;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->_weapon = &weapon;
}

void HumanB::attack(void)
{
    if (!this->_weapon)
        return;
    std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl; // Use arrow operator on the pointer to weapon
}