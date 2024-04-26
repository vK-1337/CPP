#include "Zombie.hpp"

int main(void)
{
    Zombie* horde = horde->zombieHorde(5, "Boubou");
    for (int i = 0; i < 5; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
}