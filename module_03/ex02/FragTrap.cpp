#include "FragTrap.h"
#include <iostream>
#include <string>
#include "ClapTrap.h"

FragTrap::FragTrap() {}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  setHitPoints(100);
  setEnergyPoints(100);
  setAttackDamage(30);
  std::cout << "A new FragTrap named " << getName() << " was created!"
            << std::endl;
}

FragTrap::FragTrap(FragTrap& other) : ClapTrap(other) {
  std::cout << "FragTrap " << getName() << " was duplicated." << std::endl;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap " << getName() << " was destroyed!" << std::endl;
}

void FragTrap::highFivesGuys() {
  std::cout << "FragTrap " << getName() << " is offering a high five."
            << std::endl;
}
