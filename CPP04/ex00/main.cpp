#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal *meta = new Animal();
    const Animal *i = new Cat();
    const Animal *j = new Dog();
    const WrongAnimal *k = new WrongCat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << k->getType() << " " << std::endl;
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