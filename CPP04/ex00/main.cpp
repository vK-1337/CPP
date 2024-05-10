#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal *meta = new Animal();
    const Animal *i = new Cat();
    const Animal *j = new Dog();
    const WrongAnimal *k = new WrongCat();
    std::cout << "Type: " << j->getType() << std::endl;
    std::cout << "Type: " << i->getType() << std::endl;
    std::cout << "Type: " << k->getType() << std::endl;
    i->makeSound();
    j->makeSound();
    k->makeSound();
    meta->makeSound();
    delete meta;
    delete i;
    delete j;
    delete k;
    return (0);
}