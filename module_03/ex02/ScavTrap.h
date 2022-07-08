#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.h"

#include <string>

class ScavTrap : public ClapTrap {
  bool gateKeeperMode;

 public:
  ScavTrap();
  ScavTrap(std::string name);
  ScavTrap(ScavTrap& other);

  ~ScavTrap();

  void guardGate();

  void attack(const std::string& target);
};

#endif
