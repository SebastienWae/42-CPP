#include "FragTrap.h"

#include <iostream>
#include <string>

#include "ClapTrap.h"

FragTrap::FragTrap() {
  hit_points = 100;
  energy_points = 100;
  attack_damage = 30;
  std::cout << "FragTrap " << name << ": default constructor" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  hit_points = 100;
  energy_points = 100;
  attack_damage = 30;
  std::cout << "FragTrap " << name << ": name constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
  std::cout << "FragTrap " << name << ": copy constructor" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
  std::cout << "FragTrap " << name << ": copy operator" << std::endl;
  name = other.name;
  hit_points = other.hit_points;
  energy_points = other.energy_points;
  attack_damage = other.attack_damage;
  return *this;
}

FragTrap::~FragTrap() { std::cout << "FragTrap " << name << ": destructor" << std::endl; }

void FragTrap::attack(const std::string& target) {
  if (hit_points == 0) {
    std::cout << "FragTrap " << name << ": Cannot attack. Not hit points left" << std::endl;
  } else if (energy_points == 0) {
    std::cout << "FragTrap " << name << ": Cannot attack. Not energy points left" << std::endl;
  } else {
    std::cout << "FragTrap " << name << ": Attacked " << target << " and delt " << attack_damage
              << " damages" << std::endl;
    reduceEnergyPoints(1);
  }
}

void FragTrap::highFivesGuys() {
  std::cout << "FragTrap " << name << ": Is offering a high five" << std::endl;
}
