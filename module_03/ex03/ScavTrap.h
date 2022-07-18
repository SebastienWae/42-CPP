#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <string>

#include "ClapTrap.h"

class ScavTrap : virtual public ClapTrap {
  bool gateKeeperMode_;

public:
  ScavTrap();
  ScavTrap(std::string name);
  ScavTrap(const ScavTrap& other);

  ScavTrap& operator=(const ScavTrap& other);

  ~ScavTrap();

  virtual void attack(const std::string& target);

  void guardGate();
};

#endif
