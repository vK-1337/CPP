#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap: public ScavTrap
{
    public:
        FragTrap(std::string name);
        ~FragTrap();
        void highFiveGuys(void);
};

#endif