#include "DiamondTrap.h"

#include <iostream>
#include <string>

#include "ClapTrap.h"
#include "FragTrap.h"
#include "ScavTrap.h"

DiamondTrap::DiamondTrap() {
  hit_points = FragTrap::hit_points;
  energy_points = ScavTrap::energy_points;
  attack_damage = FragTrap::attack_damage;
  Log("DiamondTrap", "default constructor");
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), name(name) {
  hit_points = FragTrap::hit_points;
  energy_points = ScavTrap::energy_points;
  attack_damage = FragTrap::attack_damage;
  Log("DiamondTrap", "name constructor");
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), FragTrap(other), ScavTrap(other), name(other.name) {
  Log("DiamondTrap", "copy constructor");
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& other) {
  const ClapTrap& ct = other;
  ClapTrap::name = ct.GetName();
  name = other.name;
  hit_points = other.hit_points;
  energy_points = other.energy_points;
  attack_damage = other.attack_damage;
  Log("DiamondTrap", "copy operator");
  return *this;
}

DiamondTrap::~DiamondTrap() { Log("DiamondTrap", "destructor"); }

void DiamondTrap::Attack(const std::string& target) {
  if (hit_points == 0) {
    Log("DiamondTrap", "cannot attack. No hit points left");
  } else if (energy_points == 0) {
    Log("DiamondTrap", "cannot attack. No energy points left");
  } else {
    Log("DiamondTrap", "dealt " + SSTR(attack_damage) + " of damage to " + target);
    ReduceEnergyPoints(1);
  }
}

void DiamondTrap::WhoAmI() const {
  std::cout << "DiamondTrap name: " << name << std::endl;
  std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}
