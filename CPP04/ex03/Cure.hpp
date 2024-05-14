#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
  public:
    Cure();
    ~Cure();
    Cure(const Cure &rhs);
    Cure &operator=(const Cure& rhs);
    void use(ICharacter& target);
};

#endif
