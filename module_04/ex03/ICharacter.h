#ifndef ICHARACTER_H
#define ICHARACTER_H

#include <string>

#include "AMateria.h"

class ICharacter {
public:
  virtual ~ICharacter() {}
  virtual std::string const& GetName() const = 0;
  virtual void Equip(AMateria* m) = 0;
  virtual void Unequip(int idx) = 0;
  virtual void Use(int idx, ICharacter& target) = 0;
  virtual AMateria* GetItem(int idx) const = 0;
};

#endif
