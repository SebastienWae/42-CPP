#include "AMateria.h"
#include "Character.h"
#include "Cure.h"
#include "Ice.h"
#include "MateriaSource.h"

int main() {
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  ICharacter* me = new Character("steve");
  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  tmp = src->createMateria("test");
  ICharacter* bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  tmp = me->getItem(0);
  me->unequip(0);
  delete tmp;
  delete bob;
  delete me;
  delete src;
  return 0;
}
