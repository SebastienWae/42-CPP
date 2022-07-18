#include "Character.h"

#include <iostream>

#include "AMateria.h"
#include "ICharacter.h"

Character::Character() {
  for (int i = 0; i < INVENTORY_SIZE; ++i) {
    inventory[i] = NULL;
  }
}

Character::Character(std::string const& name) : name(name) {
  for (int i = 0; i < INVENTORY_SIZE; ++i) {
    inventory[i] = NULL;
  }
}

Character::Character(Character const& other) : name(other.name) {
  for (int i = 0; i < INVENTORY_SIZE; ++i) {
    AMateria* item = other.inventory[i];
    if (item != NULL) {
      inventory[i] = item->clone();
    } else {
      inventory[i] = NULL;
    }
  }
}

Character::~Character() {
  for (int i = 0; i < INVENTORY_SIZE; ++i) {
    AMateria* item = inventory[i];
    if (item != NULL) {
      delete item;
    }
  }
}

Character& Character::operator=(Character const& other) {
  if (this == &other) {
    return *this;
  }

  name = other.name;
  for (int i = 0; i < INVENTORY_SIZE; ++i) {
    AMateria* item = inventory[i];
    if (item != NULL) {
      delete item;
    }
    item = other.inventory[i];
    if (item != NULL) {
      inventory[i] = item->clone();
    } else {
      inventory[i] = NULL;
    }
  }
  return *this;
}

std::string const& Character::getName() const { return name; }

void Character::equip(AMateria* m) {
  for (int i = 0; i < INVENTORY_SIZE; ++i) {
    if (inventory[i] == NULL) {
      std::cout << name << " equiped " << m->getType() << std::endl;
      inventory[i] = m;
      return;
    }
  }
}

void Character::unequip(int idx) {
  if (idx >= 0 && idx < INVENTORY_SIZE) {
    AMateria* item = inventory[idx];
    if (item != NULL) {
      std::cout << name << " unequiped " << item->getType() << std::endl;
      inventory[idx] = NULL;
    }
  }
}

void Character::use(int idx, ICharacter& target) {
  if (idx >= 0 && idx < INVENTORY_SIZE) {
    AMateria* item = inventory[idx];
    if (item != NULL) {
      item->use(target);
    }
  }
}

AMateria* Character::getItem(int idx) const {
  if (idx >= 0 && idx < INVENTORY_SIZE) {
    return inventory[idx];
  }
  return NULL;
}
