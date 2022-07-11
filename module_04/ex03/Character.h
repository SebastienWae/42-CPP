#ifndef CHARACTER_H
#define CHARACTER_H

#include <cstddef>

#include "AMateria.h"
#include "ICharacter.h"

#define INVENTORY_SIZE 4

class Character : public ICharacter {
  std::string name_;
  AMateria* inventory_[INVENTORY_SIZE];
  std::size_t inventory_cursor_;

public:
  Character();
  Character(const std::string& name);
  Character(const Character& other);

  ~Character();

  Character& operator=(const Character& other);

  virtual std::string const& GetName() const;
  virtual void Equip(AMateria* m);
  virtual void Unequip(int idx);
  virtual void Use(int idx, ICharacter& target);
  virtual AMateria* GetItem(int idx) const;
};

#endif
