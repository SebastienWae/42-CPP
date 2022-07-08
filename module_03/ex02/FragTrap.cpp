#include "FragTrap.h"
#include <iostream>
#include <string>
#include "ClapTrap.h"

FragTrap::FragTrap() {}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  hit_points = 100;
  energy_points = 100;
  attack_damage = 30;
  std::cout << "A new FragTrap named " << name << " was created!" << std::endl;
}

FragTrap::FragTrap(FragTrap& other) : ClapTrap(other) {
  name = other.name;
  hit_points = other.hit_points;
  energy_points = other.energy_points;
  attack_damage = other.attack_damage;
  std::cout << "FragTrap " << name << " was duplicated." << std::endl;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap " << name << " was destroyed!" << std::endl;
}

void FragTrap::highFivesGuys() {
  std::cout << "FragTrap " << name << " is offering a high five." << std::endl;
}
