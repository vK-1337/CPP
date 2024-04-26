#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap " << this->_name << " has been created." << std::endl;
    return;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->_name << " has been destroyed." << std::endl;
    return;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->_hitPoints <= 0 || this->_energyPoints == 0)
    {
        if (this->_energyPoints == 0)
            std::cout << "ScavTrap " << this->_name << " has not enough energy points to do anything." << std::endl;
        else if (this->_hitPoints <= 0)
            std::cout << "ScavTrap " << this->_name << " is already broken!";
    }
    else
    {
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    }
    return;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name << " is now in Gatekeeper mode" << std::endl;
    return;
}
