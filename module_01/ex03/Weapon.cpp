#include "Weapon.h"

const std::string& Weapon::getType() const {
  return type;
}

void Weapon::setType(std::string new_type) {
  type = new_type;
}

Weapon::Weapon(std::string type) : type(type) {}
