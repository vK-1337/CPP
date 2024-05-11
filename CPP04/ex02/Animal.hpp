#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class AAnimal
{
    protected:
        std::string _type;

    public:
        AAnimal();
        virtual ~AAnimal();
        AAnimal(const AAnimal &rhs);
        virtual AAnimal &operator=(const AAnimal& rhs);
        virtual void makeSound() const = 0;
        std::string getType() const;
};

#endif
