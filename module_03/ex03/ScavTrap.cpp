#include "ScavTrap.h"

#include <iostream>
#include <string>

#include "ClapTrap.h"

ScavTrap::ScavTrap() {
  hit_points = 100;
  energy_points = 50;
  attack_damage = 20;
  Log("ScavTrap", "default constructor");
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), gateKeeperMode_(false) {
  hit_points = 100;
  energy_points = 50;
  attack_damage = 20;
  Log("ScavTrap", "name constructor");
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) { Log("ScavTrap", "copy constructor"); }

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
  name = other.name;
  hit_points = other.hit_points;
  energy_points = other.energy_points;
  attack_damage = other.attack_damage;
  Log("ScavTrap", "copy operator");
  return *this;
}

ScavTrap::~ScavTrap() { Log("ScavTrap", "destructor"); }

void ScavTrap::Attack(const std::string& target) {
  if (hit_points == 0) {
    Log("ScavTrap", "cannot attack. No hit points left");
  } else if (energy_points == 0) {
    Log("ScavTrap", "cannot attack. No energy points left");
  } else {
    Log("ScavTrap", "dealt " + SSTR(attack_damage) + " of damage to " + target);
    ReduceEnergyPoints(1);
  }
}

void ScavTrap::GuardGate() {
  if (gateKeeperMode_) {
    Log("ScavTrap", "is already in gate keeper mode");
  } else {
    Log("ScavTrap", "is now in gate keeper mode");
  }
}
