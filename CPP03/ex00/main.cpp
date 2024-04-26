#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap clap("Clappy");
    clap.attack("Vincent");
    clap.takeDamage(5);
    clap.beRepaired(5);
    clap.takeDamage(5);
    clap.takeDamage(5);
    clap.beRepaired(1);
    return (0);
}