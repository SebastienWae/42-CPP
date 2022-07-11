#include "FragTrap.h"

#include <iostream>
#include <string>

#include "ClapTrap.h"

FragTrap::FragTrap() {
  hit_points = 100;
  energy_points = 100;
  attack_damage = 30;
  Log("FragTrap", "default constructor");
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  hit_points = 100;
  energy_points = 100;
  attack_damage = 30;
  Log("FragTrap", "name constructor");
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) { Log("FragTrap", "copy constructor"); }

FragTrap& FragTrap::operator=(const FragTrap& other) {
  name = other.name;
  hit_points = other.hit_points;
  energy_points = other.energy_points;
  attack_damage = other.attack_damage;
  Log("FragTrap", "copy operator");
  return *this;
}

FragTrap::~FragTrap() { Log("FragTrap", "destructor"); }

void FragTrap::Attack(const std::string& target) {
  if (hit_points == 0) {
    Log("FragTrap", "cannot attack. No hit points left");
  } else if (energy_points == 0) {
    Log("FragTrap", "cannot attack. No energy points left");
  } else {
    Log("FragTrap", "dealt " + SSTR(attack_damage) + " of damage to " + target);
    ReduceEnergyPoints(1);
  }
}

void FragTrap::HighFivesGuys() { Log("FragTrap", "is offering a high five"); }
