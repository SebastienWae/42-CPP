#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"

class HumanA {
  std::string name_;
  Weapon& weapon_;

public:
  void Attack(void) const;

  HumanA(std::string name, Weapon& weapon);
};

#endif
