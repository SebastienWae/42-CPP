#include "ClapTrap.h"

#include <iostream>
#include <iterator>
#include <limits>
#include <string>

ClapTrap::ClapTrap() : hit_points(10), energy_points(10), attack_damage(0) {
  Log("ClapTrap", "default constructor");
}

ClapTrap::ClapTrap(std::string name)
    : name(name), hit_points(10), energy_points(10), attack_damage(0) {
  Log("ClapTrap", "name constructor");
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name(other.name),
      hit_points(other.hit_points),
      energy_points(other.energy_points),
      attack_damage(other.attack_damage) {
  Log("ClapTrap", "copy constructor");
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
  name = other.name;
  hit_points = other.hit_points;
  energy_points = other.energy_points;
  attack_damage = other.attack_damage;
  Log("ClapTrap", "copy operator");
  return *this;
}

ClapTrap::~ClapTrap() { Log("ClapTrap", "destructor"); }

std::string ClapTrap::GetName() const { return name; }

unsigned int ClapTrap::ReduceHitPoints(unsigned int n) {
  if (n >= hit_points) {
    n = hit_points;
  }
  hit_points -= n;
  return n;
}

unsigned int ClapTrap::IncreaseHitPoints(unsigned int n) {
  if (n >= std::numeric_limits<unsigned int>::max() - hit_points) {
    n = std::numeric_limits<unsigned int>::max() - hit_points;
  }
  hit_points += n;
  return n;
}

unsigned int ClapTrap::ReduceEnergyPoints(unsigned int n) {
  if (n >= energy_points) {
    n = energy_points;
  }
  energy_points -= n;
  return n;
}

void ClapTrap::Log(const std::string& type, const std::string& msg) {
  std::cout << type << " '" << name << "': " << msg << std::endl;
}

void ClapTrap::PrintStatus() const {
  std::cout << "### " << name << " STATUS ###" << std::endl;
  std::cout << "hit points: " << hit_points << std::endl;
  std::cout << "energy points: " << energy_points << std::endl;
  std::cout << "attack damage: " << attack_damage << std::endl;
  std::cout << "address: " << this << std::endl;
}

void ClapTrap::Attack(const std::string& target) {
  if (hit_points == 0) {
    Log("ClapTrap", "cannot attack. No hit points left");
  } else if (energy_points == 0) {
    Log("ClapTrap", "cannot attack. No energy points left");
  } else {
    Log("ClapTrap", "dealt " + SSTR(attack_damage) + " of damage to " + target);
    ReduceEnergyPoints(1);
  }
}

void ClapTrap::TakeDamage(unsigned int amount) {
  if (hit_points == 0) {
    Log("ClapTrap", "is out of service");
  } else {
    amount = ReduceHitPoints(amount);
    Log("ClapTrap", "took " + SSTR(amount) + " of damage");
  }
}

void ClapTrap::BeRepaired(unsigned int amount) {
  if (hit_points == 0) {
    Log("ClapTrap", "cannot be repaired. It's out of service");
  } else if (energy_points == 0) {
    Log("ClapTrap", "cannot be repaired. Not enough energy points");
  } else {
    amount = IncreaseHitPoints(amount);
    ReduceEnergyPoints(1);
    Log("ClapTrap", "was repaired. It gained " + SSTR(amount) + " hit points");
  }
}
