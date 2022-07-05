#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.h"

class HumanB {
  Weapon* weapon;
  std::string name;

 public:
  void attack(void) const;
  void setWeapon(Weapon& new_weapon);

  HumanB(std::string name);
};

#endif
