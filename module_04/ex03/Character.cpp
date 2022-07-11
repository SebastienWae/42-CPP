#include "Character.h"

#include <iostream>

#include "AMateria.h"
#include "ICharacter.h"

Character::Character() {
  for (int i = 0; i < INVENTORY_SIZE; ++i) {
    inventory_[i] = NULL;
  }
}

Character::Character(const std::string& name) : name_(name) {
  for (int i = 0; i < INVENTORY_SIZE; ++i) {
    inventory_[i] = NULL;
  }
}

Character::Character(const Character& other) : name_(other.GetName()) {
  for (int i = 0; i < INVENTORY_SIZE; ++i) {
    AMateria* item = other.inventory_[i];
    if (item != NULL) {
      inventory_[i] = item->Clone();
    } else {
      inventory_[i] = NULL;
    }
  }
}

Character::~Character() {
  for (int i = 0; i < INVENTORY_SIZE; ++i) {
    AMateria* item = inventory_[i];
    if (item != NULL) {
      delete item;
    }
  }
}

Character& Character::operator=(const Character& other) {
  if (this == &other) {
    return *this;
  }

  name_ = other.GetName();
  for (int i = 0; i < INVENTORY_SIZE; ++i) {
    AMateria* item = inventory_[i];
    if (item != NULL) {
      delete item;
    }
    item = other.inventory_[i];
    if (item != NULL) {
      inventory_[i] = item->Clone();
    } else {
      inventory_[i] = NULL;
    }
  }
  return *this;
}

std::string const& Character::GetName() const { return name_; }

void Character::Equip(AMateria* m) {
  for (int i = 0; i < INVENTORY_SIZE; ++i) {
    if (inventory_[i] == NULL) {
      std::cout << GetName() << " equiped " << m->GetType() << std::endl;
      inventory_[i] = m;
      return;
    }
  }
}

void Character::Unequip(int idx) {
  if (idx >= 0 && idx < INVENTORY_SIZE) {
    AMateria* item = inventory_[idx];
    if (item != NULL) {
      std::cout << GetName() << " unequiped " << item->GetType() << std::endl;
      inventory_[idx] = NULL;
    }
  }
}

void Character::Use(int idx, ICharacter& target) {
  if (idx >= 0 && idx < INVENTORY_SIZE) {
    AMateria* item = inventory_[idx];
    if (item != NULL) {
      item->Use(target);
    }
  }
}

AMateria* Character::GetItem(int idx) const {
  if (idx >= 0 && idx < INVENTORY_SIZE) {
    return inventory_[idx];
  }
  return NULL;
}
