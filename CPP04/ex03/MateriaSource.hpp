#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "header.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria * materias[4];
    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(const MateriaSource &rhs);
        MateriaSource &operator=(const MateriaSource& rhs);
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif
