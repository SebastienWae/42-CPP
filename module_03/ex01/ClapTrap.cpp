#include "ClapTrap.h"

#include <iostream>
#include <iterator>
#include <limits>
#include <string>

ClapTrap::ClapTrap() : hit_points(10), energy_points(10), attack_damage(0) {
  std::cout << "ClapTrap " << name << ": default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : name(name), hit_points(10), energy_points(10), attack_damage(0) {
  std::cout << "ClapTrap " << name << ": name constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name(other.name),
      hit_points(other.hit_points),
      energy_points(other.energy_points),
      attack_damage(other.attack_damage) {
  std::cout << "ClapTrap " << name << ": copy constructor" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
  std::cout << "ClapTrap " << name << ": copy operator" << std::endl;
  name = other.name;
  hit_points = other.hit_points;
  energy_points = other.energy_points;
  attack_damage = other.attack_damage;
  return *this;
}

ClapTrap::~ClapTrap() { std::cout << "ClapTrap " << name << ": destructor" << std::endl; }

std::string ClapTrap::getName() const { return name; }

unsigned int ClapTrap::reduceHitPoints(unsigned int n) {
  if (n >= hit_points) {
    n = hit_points;
  }
  hit_points -= n;
  return n;
}

unsigned int ClapTrap::increaseHitPoints(unsigned int n) {
  if (n >= std::numeric_limits<unsigned int>::max() - hit_points) {
    n = std::numeric_limits<unsigned int>::max() - hit_points;
  }
  hit_points += n;
  return n;
}

unsigned int ClapTrap::reduceEnergyPoints(unsigned int n) {
  if (n >= energy_points) {
    n = energy_points;
  }
  energy_points -= n;
  return n;
}

void ClapTrap::printStatus() const {
  std::cout << "### " << name << " STATUS ###" << std::endl;
  std::cout << "hit points: " << hit_points << std::endl;
  std::cout << "energy points: " << energy_points << std::endl;
  std::cout << "attack damage: " << attack_damage << std::endl;
  std::cout << "address: " << this << std::endl;
}

void ClapTrap::attack(const std::string& target) {
  if (hit_points == 0) {
    std::cout << "ClapTrap " << name << ": Cannot attack. Not hit points left" << std::endl;
  } else if (energy_points == 0) {
    std::cout << "CalpTrap " << name << ": Cannot attack. Not energy points left" << std::endl;
  } else {
    std::cout << "ClapTrap " << name << ": Attacked " << target << " and delt " << attack_damage
              << " damages" << std::endl;
    reduceEnergyPoints(1);
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (hit_points == 0) {
    std::cout << "ClapTrap " << name << ": Is already out of service" << std::endl;
  } else {
    amount = reduceHitPoints(amount);
    std::cout << "ClapTrap " << name << ": Took " << amount << " points of damage" << std::endl;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (hit_points == 0) {
    std::cout << "ClapTrap " << name << ": Cannot be repaired. Already out of service" << std::endl;
  } else if (energy_points == 0) {
    std::cout << "ClapTrap " << name << ": Cannot be repaired. Not enough energy points"
              << std::endl;
  } else {
    amount = increaseHitPoints(amount);
    if (amount == 0) {
      std::cout << "ClapTrap " << name << ": Is already fully repaired" << std::endl;
    } else {
      std::cout << "ClapTrap " << name << ": Was repaired. It gained " << amount << " hit points"
                << std::endl;
    }
    reduceEnergyPoints(1);
  }
}
