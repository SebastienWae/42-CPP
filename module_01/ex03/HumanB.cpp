#include "HumanB.h"

#include <iostream>

#include "Weapon.h"

HumanB::HumanB(std::string name) : name(name) {}

void HumanB::attack() const {
  std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& new_weapon) {
  weapon = &new_weapon;
}
