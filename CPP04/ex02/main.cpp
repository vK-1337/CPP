#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const AAnimal *cat = new Cat();
    const AAnimal *dog = new Dog();
    delete cat;
    delete dog;

    const AAnimal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };

    for ( int i = 0; i < 4; i++ ) {
        delete animals[i];
    }

    Brain test;

    test.setIdea(0, "Eat");
    test.setIdea(1, "Meow");
    test.setIdea(2, "Bark");

    std::cout << test.getIdea(0) << std::endl;
    std::cout << test.getIdea(1) << std::endl;
    std::cout << test.getIdea(2) << std::endl;

    Brain copy;

    copy = test;

    test.setIdea(0, "EAAAAT");

    std::cout << copy.getIdea(0) << std::endl;
    std::cout << copy.getIdea(1) << std::endl;
    std::cout << copy.getIdea(2) << std::endl;
    
    copy = test;

    std::cout << copy.getIdea(0) << std::endl;
    std::cout << copy.getIdea(1) << std::endl;
    std::cout << copy.getIdea(2) << std::endl;
    return (0);
}