#include "Zombie.hpp"

int main(void)
{
    std::string zombieName;
    Zombie *zombi;

    std::cout << std::endl << "Welcome to zombie simulator !" << std::endl;
    std::cout << std::endl << "Creating a zombie in the stack" << std::endl;
    std::cout << std::endl << "Can you give a name for the Zombie ?" << std::endl;
    std::cin >> zombieName;
    randomChump(zombieName);
    std::cout << std::endl << "Now creating a zombie in the heap" << std::endl;
    std::cout << std::endl << "Can you give a name for the Zombie ?" << std::endl;
    std::cin >> zombieName;
    zombi = newZombie(zombieName);
    std::cout << "Now asking to the zombie in the heap to announce himself" << std::endl;
    zombi->announce();
    std::cout << "Now deleting " << zombieName << "." << std::endl;
    delete(zombi);
    std::cout << std::endl << "Bye bye !" << std::endl;
    return (0);
}