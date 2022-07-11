#include "ScavTrap.h"
#include <iostream>
#include <string>
#include "ClapTrap.h"

ScavTrap::ScavTrap() {}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), gateKeeperMode(false) {
  setHitPoints(100);
  setEnergyPoints(50);
  setAttackDamage(20);
  std::cout << "A new ScavTrap named " << name << " was created!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& other) : ClapTrap(other) {
  std::cout << "ScavTrap " << getName() << " was duplicated." << std::endl;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << getName() << " was destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
  if (getHitPoints() == 0) {
    std::cout << "ScavTrap " << getName() << " cannot attack " << target
              << ". It's broken." << std::endl;
  } else if (getEnergyPoints() == 0) {
    std::cout << "ScavTrap " << getName() << " cannot attack " << target
              << ". It's out of energy." << std::endl;
  } else {
    std::cout << "ScavTrap " << getName() << " attacks " << target
              << ", causing " << getAttackDamage() << " points of "
              << "damage!" << std::endl;
    reduceEnergyPoints(1);
  }
}

void ScavTrap::guardGate() {
  if (gateKeeperMode) {
    std::cout << "ScavTrap " << getName() << " is already in gate keeper mode."
              << std::endl;
  } else {
    gateKeeperMode = true;
    std::cout << "ScavTrap " << getName() << " is now in gate keeper mode."
              << std::endl;
  }
}
