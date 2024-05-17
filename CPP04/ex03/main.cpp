#include "header.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

// std::vector<AMateria*> trash_floor;

// void clear_floor(std::vector<AMateria*> trashfloor)
// {
//     if (trash_floor.size() > 0)
//     {
//         for (int i = 0; i < trash_floor.size(); i++)
//         {
//             if (trash_floor[i])
//                 delete trash_floor[i];
//             trash_floor[i] = nullptr;
//         }
//     }
//     trash_floor.clear();
//     return;
// }

int main (void)
{
    IMateriaSource* src = new MateriaSource();
    ICharacter* me = new Character("Vince");
    Character* vlad = new Character("Vlad");
    ICharacter* bob = new Character("bob");
    AMateria* tmp;

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    tmp = src->createMateria("ice");

    me->equip(tmp);

    tmp = src->createMateria("cure");
    me->equip(tmp);


    me->use(0, *bob);
    me->use(1, *bob);
    me->equip(NULL);

    vlad->equip(src->createMateria("ice"));
    vlad->equip(src->createMateria("cure"));

    tmp = vlad->getMateriaAdress(0);
    vlad->unequip(0);

    delete vlad;
    delete tmp;
    delete bob;
    delete me;
    delete src;

    // clear_floor(trash_floor);
    
    return 0;
}