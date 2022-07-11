#include "HumanA.h"

#include <iostream>

#include "Weapon.h"

HumanA::HumanA(std::string name, Weapon& weapon) : name_(name), weapon_(weapon) {}

void HumanA::Attack() const {
  std::cout << name_ << " attacks with their " << weapon_.GetType() << std::endl;
}
