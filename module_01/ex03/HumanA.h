#ifndef HUMAN_A_H
#define HUMAN_A_H

#include <string>

#include "Weapon.h"

class HumanA {
  std::string name;
  Weapon& weapon;

public:
  HumanA(std::string name, Weapon& weapon);

  void attack() const;
};

#endif
