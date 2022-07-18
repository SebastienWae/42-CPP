#ifndef CHARACTER_H
#define CHARACTER_H

#include <cstddef>

#include "AMateria.h"
#include "ICharacter.h"

#define INVENTORY_SIZE 4

class Character : public ICharacter {
  std::string name;
  AMateria* inventory[INVENTORY_SIZE];

public:
  Character();
  Character(std::string const& name);
  Character(Character const& other);

  ~Character();

  Character& operator=(Character const& other);

  virtual std::string const& getName() const;
  virtual void equip(AMateria* m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter& target);
  virtual AMateria* getItem(int idx) const;
};

#endif
