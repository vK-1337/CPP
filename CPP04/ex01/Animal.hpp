#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string _type;

    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal &rhs);
        virtual Animal &operator=(const Animal& rhs);
        virtual void makeSound() const;
        std::string getType() const;
};

#endif
