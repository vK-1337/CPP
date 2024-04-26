#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap clap("ClapTrap");
    ScavTrap scav("ScavTrap");
    FragTrap frag("FragTrap");
    clap.attack("Vincent");
    scav.attack("Vincent");
    scav.guardGate();
    frag.highFiveGuys();
    return (0);
}