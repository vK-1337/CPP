#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name)
{
    std::cout << "ClapTrap " << this->_name << " has been created." << std::endl;
    return;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->_name << " has been destroyed." << std::endl;
    return;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_hitPoints <= 0 || this->_energyPoints == 0)
    {
        if (this->_energyPoints == 0)
            std::cout << "ClapTrap " << this->_name << " has not enough energy points to do anything." << std::endl;
        else if (this->_hitPoints <= 0)
            std::cout << "ClapTrap " << this->_name << " is already broken!";
    }
    else
    {
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    }
    return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints <= 0 || this->_energyPoints == 0)
    {
        if (this->_energyPoints == 0)
            std::cout << "ClapTrap " << this->_name << " has not enough energy points to do anything." << std::endl;
        else if (this->_hitPoints <= 0)
            std::cout << "ClapTrap " << this->_name << " is already broken!";
    }
    else
    {
        std::cout << "ClapTrap " << this->_name << " take " << amount << " points of damage! It has " << this->_hitPoints << "left." << std::endl;
        this->_hitPoints -= amount;
        if (this->_hitPoints <= 0)
            std::cout << "ClapTrap " << this->_name << " is totally broken. " << std::endl;
    }
    return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoints <= 0 || this->_energyPoints == 0)
    {
        if (this->_energyPoints == 0)
            std::cout << "ClapTrap " << this->_name << " has not enough energy points to do anything." << std::endl;
        else if (this->_hitPoints <= 0)
            std::cout << "ClapTrap " << this->_name << " is totally broken & can't be repaired." << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << this->_name << " has been repaired for " << amount << "hit points, he has now " << this->_hitPoints << std::endl;
        this->_hitPoints += amount;
        this->_energyPoints--;
    }
    return;
}