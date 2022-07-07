#include "ScavTrap.h"
#include <iostream>
#include <string>
#include "ClapTrap.h"

ScavTrap::ScavTrap() {}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), gateKeeperMode(false) {
  hit_points = 100;
  energy_points = 50;
  attack_damage = 20;
  std::cout << "A new ScavTrap named " << name << " was created!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& other) : ClapTrap(other) {
  name = other.name;
  hit_points = other.hit_points;
  energy_points = other.energy_points;
  attack_damage = other.attack_damage;
  std::cout << "ScavTrap " << name << " was duplicated." << std::endl;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << name << " was destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
  if (hit_points == 0) {
    std::cout << "ScavTrap " << name << " cannot attack " << target
              << ". It's broken." << std::endl;
  } else if (energy_points == 0) {
    std::cout << "ScavTrap " << name << " cannot attack " << target
              << ". It's out of energy." << std::endl;
  } else {
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing "
              << attack_damage << " points of "
              << "damage!" << std::endl;
    energy_points--;
  }
}

void ScavTrap::guardGate() {
  if (gateKeeperMode) {
    std::cout << "ScavTrap " << name << " is already in gate keeper mode."
              << std::endl;
  } else {
    gateKeeperMode = true;
    std::cout << "ScavTrap " << name << " is now in gate keeper mode."
              << std::endl;
  }
}
