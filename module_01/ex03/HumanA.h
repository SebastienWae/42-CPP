#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"

class HumanA {
  std::string name;
  Weapon weapon;

 public:
  void attack(void) const;

  HumanA(std::string name, Weapon &weapon);
};

#endif
