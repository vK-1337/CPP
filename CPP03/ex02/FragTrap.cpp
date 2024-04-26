#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ScavTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " has been created." << std::endl;
	return ;
}
FragTrap::~FragTrap()
{
	return ;
}

void	highFiveGuys(void)
{
	std::cout << "Positive high fives request!!" << std::endl;
	return ;
}