#include "ClapTrap.h"
#include <iostream>
#include <limits>
#include <string>

ClapTrap::ClapTrap() {}

ClapTrap::ClapTrap(std::string name)
    : name(name), hit_points(10), energy_points(10), attack_damage(0) {
  std::cout << "A new ClapTrap named " << name << " was created!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& other) {
  name = other.name;
  hit_points = other.hit_points;
  energy_points = other.energy_points;
  attack_damage = other.attack_damage;
  std::cout << "ClapTrap " << name << " was duplicated." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy) {
  name = copy.name;
  hit_points = copy.hit_points;
  energy_points = copy.energy_points;
  attack_damage = copy.attack_damage;
  std::cout << "ClapTrap " << name << " was copied." << std::endl;
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << name << " was destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
  if (hit_points == 0) {
    std::cout << "ClapTrap " << name << " cannot attack " << target
              << ". It's broken." << std::endl;
  } else if (energy_points == 0) {
    std::cout << "ClapTrap " << name << " cannot attack " << target
              << ". It's out of energy." << std::endl;
  } else {
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
              << attack_damage << " points of "
              << "damage!" << std::endl;
    energy_points--;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (hit_points == 0) {
    std::cout << "Stop attacking ClapTrap " << name << " it's already broken!"
              << std::endl;
  } else {
    std::cout << "ClapTrap " << name << " took " << amount
              << " points of damage!" << std::endl;
    if (amount >= hit_points) {
      std::cout << "ClapTrap " << name << " is out of service." << std::endl;
      hit_points = 0;
    } else {
      hit_points -= amount;
    }
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (hit_points == 0) {
    std::cout << "ClapTrap " << name << " cannot be repaired." << std::endl;
  } else if (energy_points == 0) {
    std::cout << "ClapTrap " << name
              << " doesn't have enough energy to repair itself." << std::endl;
  } else {
    if (amount >= std::numeric_limits<unsigned int>::max() - hit_points) {
      amount = std::numeric_limits<unsigned int>::max() - hit_points;
    }
    std::cout << "ClapTrap " << name << " repaired itself of " << amount
              << " hit points." << std::endl;
    energy_points--;
    hit_points += amount;
  }
}
