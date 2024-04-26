#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name),
	ScavTrap(name)
{
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	FragTrap::_hitPoints = 100;
	ScavTrap::_energyPoints = 50;
	FragTrap::_attackDamage = 30;
}

void DiamondTrap::whoAmI()
{
	std::cout << "My basic name is " << this->_name << std::endl;
	std::cout << "My ClapTrap name is " << this->ClapTrap::_name << std::endl;
	return ;
}
