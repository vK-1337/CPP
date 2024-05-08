#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " has been created." << std::endl;
	return ;
}
FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->_name << " has been destroyed." << std::endl;
	return ;
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << "Positive high fives request!!" << std::endl;
	return ;
}