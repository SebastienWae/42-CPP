#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.h"

#include <string>

class FragTrap : public ClapTrap {
 public:
  FragTrap();
  FragTrap(std::string name);
  FragTrap(FragTrap& other);

  ~FragTrap();

  void highFivesGuys();
};

#endif