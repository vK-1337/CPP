#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:
        std::string _name;
        void setName( std::string name );

    public:
        Zombie( std::string name = "z");
        ~Zombie( void );
        void announce( void );
        Zombie* zombieHorde( int N, std::string name );
};

#endif