#include "HumanB.h"

#include <iostream>
#include <string>

#include "Weapon.h"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

void HumanB::setWeapon(Weapon& weapon) { this->weapon = &weapon; }

void HumanB::attack() const {
  if (weapon == NULL) {
    std::cout << name << " is unarmed" << std::endl;
    return;
  }
  std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
