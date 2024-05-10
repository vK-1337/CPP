#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal *cat = new Cat();
    const Animal *dog = new Dog();
    Brain *brain1 = new Brain();
    Brain *brain2 = new Brain();
    delete(cat);
    delete(dog);
    return (0);
}