#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource()
{
     for (int i = 0; i < 4; i++)
        this->materias[i] = nullptr;
    return;
}
MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->materias[i])
        delete this->materias[i];
        this->materias[i] = nullptr;
    };
}
MateriaSource::MateriaSource(const MateriaSource &rhs)
{
    *this = rhs;
    std::cout << "MateriaSource copy constructor called" << std::endl;
    return;
}

MateriaSource &MateriaSource::operator=(const MateriaSource& rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->materias[i])
                delete this->materias[i];
                this->materias[i] = nullptr;
        }
        for (int i = 0; i < 4; i++)
        {
            if (rhs.materias[i])
                this->materias[i] = rhs.materias[i]->clone();
        }
    }
    std::cout << "A MateriaSource has been copied with copy assignement operator." << std::endl;
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (m == nullptr)
        return;
   for (int i = 0; i < 4; i++)
   {
        if (this->materias[i] == nullptr)
        {
            this->materias[i] = m;
            return;
        }
   }
   std::cout << "MateriaSource is already full, can't learn more." << std::endl;
   return;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->materias[i]->getType() == type)
            return this->materias[i]->clone();
    }
    std::cout << "Unknown type of Materia" << std::endl;
    return (0);
}