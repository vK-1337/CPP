#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string _type;

    public:
        WrongAnimal();
        virtual ~WrongAnimal();
        WrongAnimal(const WrongAnimal &rhs);
        virtual WrongAnimal &operator=(const WrongAnimal& rhs);
        virtual void makeSound() const;
        std::string getType() const;
};

#endif