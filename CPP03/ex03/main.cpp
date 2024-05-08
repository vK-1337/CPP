#include "DiamondTrap.hpp"

int main( void )
{
    DiamondTrap vlad( "Vlad" );
    DiamondTrap vlad2( vlad );
    DiamondTrap vlad3(".");

    vlad.whoAmI();
    vlad2.whoAmI();
    vlad3 = vlad;
    vlad3.whoAmI();

    vlad.attack( "the air" );
    vlad.takeDamage( 10 );
    vlad.beRepaired( 10 );

    return 0;
}