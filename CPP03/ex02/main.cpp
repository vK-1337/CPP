#include "FragTrap.hpp"

int main()
{
    ClapTrap clap("ClapTrap");
    ScavTrap scav("ScavTrap");
    FragTrap frag("FragTrap");
    clap.attack("Vincent");
    scav.attack("Vincent");
    scav.guardGate();
    frag.guardGate();
    frag.highFiveGuys();
    return (0);
}