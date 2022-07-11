#include "HumanB.h"

#include <iostream>

#include "Weapon.h"

HumanB::HumanB(std::string name) : name_(name) {}

void HumanB::Attack() const {
  std::cout << name_ << " attacks with their " << weapon_->GetType() << std::endl;
}

void HumanB::SetWeapon(Weapon& new_weapon) { weapon_ = &new_weapon; }
