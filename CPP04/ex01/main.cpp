#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal *cat = new Cat();
    const Animal *dog = new Dog();
    delete cat;
    delete dog;

    const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };

    for ( int i = 0; i < 4; i++ ) {
        delete animals[i];
    }

    Brain *test = new Brain();

    test->setIdea(0, "Eat");
    test->setIdea(1, "Meow");
    test->setIdea(2, "Bark");

    Brain *copy = test;

    Brain *copy3(test);
    Brain copy2(*test);

    Dog basic;
    {
    Dog tmp = basic;
    }

    std::cout << copy->getIdea(0) << std::endl;
    std::cout << copy->getIdea(1) << std::endl;
    std::cout << copy->getIdea(2) << std::endl;

    std::cout << copy3->getIdea(0) << std::endl;
    std::cout << copy3->getIdea(1) << std::endl;
    std::cout << copy3->getIdea(2) << std::endl;

    std::cout << copy2.getIdea(0) << std::endl;
    std::cout << copy2.getIdea(1) << std::endl;
    std::cout << copy2.getIdea(2) << std::endl;

    delete copy;
    delete test;
    return (0);
}