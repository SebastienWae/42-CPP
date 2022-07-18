#include "ScavTrap.h"

#include <iostream>
#include <string>
#include "ClapTrap.h" 

ScavTrap::ScavTrap(): gateKeeperMode(false) {
  hit_points = 100;
  energy_points = 50;
  attack_damage = 20;
  std::cout << "ScavTrap " << name << ": default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), gateKeeperMode(false) {
  hit_points = 100;
  energy_points = 50;
  attack_damage = 20;
  std::cout << "ScavTrap " << name << ": name constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other), gateKeeperMode(false) {
  std::cout << "ScavTrap " << name << ": copy constructor" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
  std::cout << "ScavTrap " << name << ": copy operator" << std::endl;
  name = other.name;
  hit_points = other.hit_points;
  energy_points = other.energy_points;
  attack_damage = other.attack_damage;
  gateKeeperMode = other.gateKeeperMode;
  return *this;
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap " << name << ": destructor" << std::endl; }

void ScavTrap::attack(const std::string& target) {
  if (hit_points == 0) {
    std::cout << "ScavTrap " << name << ": Cannot attack. Not hit points left" << std::endl;
  } else if (energy_points == 0) {
    std::cout << "ScavTrap " << name << ": Cannot attack. Not energy points left" << std::endl;
  } else {
    std::cout << "ScavTrap " << name << ": Attacked " << target << " and delt " << attack_damage
              << " damages." << std::endl;
    reduceEnergyPoints(1);
  }
}

void ScavTrap::guardGate() {
  if (gateKeeperMode) {
    std::cout << "ScavTrap " << name << ": Already in gate keeper mode" << std::endl;
  } else {
    std::cout << "ScavTravp " << name << ": Is now in gate keeper mode" << std::endl;
	gateKeeperMode = true;
  }
}
