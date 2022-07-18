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
  std::cout << "DiamondTrap " << name << ": default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), name(name) {
  hit_points = FragTrap::hit_points;
  energy_points = ScavTrap::energy_points;
  attack_damage = FragTrap::attack_damage;
  std::cout << "DiamondTrap " << name << ": name constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), FragTrap(other), ScavTrap(other), name(other.name) {
  std::cout << "DiamondTrap " << name << ": copy constructor" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& other) {
  const ClapTrap& ct = other;
  ClapTrap::name = ct.getName();
  name = other.name;
  hit_points = other.hit_points;
  energy_points = other.energy_points;
  attack_damage = other.attack_damage;
  std::cout << "DiamondTrap " << name << ": copy operator" << std::endl;
  return *this;
}

DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap " << name << ": destructor" << std::endl; }

void DiamondTrap::attack(const std::string& target) { ScavTrap::attack(target); }

void DiamondTrap::whoAmI() const {
  std::cout << "DiamondTrap name: " << name << std::endl;
  std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}
