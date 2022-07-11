#include "Weapon.h"

const std::string& Weapon::GetType() const { return type_; }

void Weapon::SetType(std::string new_type) { type_ = new_type; }

Weapon::Weapon(std::string type) : type_(type) {}
