#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.h"

class HumanB {
  Weapon* weapon_;
  std::string name_;

public:
  void Attack(void) const;
  void SetWeapon(Weapon& new_weapon);

  HumanB(std::string name);
};

#endif
