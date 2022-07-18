#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <string>

#include "ClapTrap.h"

class FragTrap : virtual public ClapTrap {
public:
  FragTrap();
  FragTrap(std::string name);
  FragTrap(const FragTrap& other);

  FragTrap& operator=(const FragTrap& other);

  ~FragTrap();

  virtual void attack(const std::string& target);

  void highFivesGuys();
};

#endif
