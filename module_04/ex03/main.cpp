#include "AMateria.h"
#include "Character.h"
#include "Cure.h"
#include "Ice.h"
#include "MateriaSource.h"

int main() {
  IMateriaSource* src = new MateriaSource();
  src->LearnMateria(new Ice());
  src->LearnMateria(new Cure());
  ICharacter* me = new Character("me");
  AMateria* tmp;
  tmp = src->CreateMateria("ice");
  me->Equip(tmp);
  tmp = src->CreateMateria("cure");
  me->Equip(tmp);
  ICharacter* bob = new Character("bob");
  me->Use(0, *bob);
  me->Use(1, *bob);
  tmp = me->GetItem(0);
  me->Unequip(0);
  delete tmp;
  delete bob;
  delete me;
  delete src;
  return 0;
}
