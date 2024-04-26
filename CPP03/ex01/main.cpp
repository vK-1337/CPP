#include "ScavTrap.hpp"

int main()
{
    ClapTrap clap("ClapTrap");
    ScavTrap scav("ScavTrap");
    clap.attack("Vincent");
    scav.attack("Vincent");
    scav.guardGate();
    return (0);
}