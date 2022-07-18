#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include <string>

#include "FragTrap.h"
#include "ScavTrap.h"

class DiamondTrap : public FragTrap, public ScavTrap {
  std::string name;

public:
  DiamondTrap();
  DiamondTrap(std::string name);
  DiamondTrap(const DiamondTrap& other);

  DiamondTrap& operator=(const DiamondTrap& other);

  ~DiamondTrap();

  virtual void attack(const std::string& target);

  void whoAmI() const;
};

#endif
