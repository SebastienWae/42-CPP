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
  std::cout << "ClapTrap " << getName() << " was destroyed!" << std::endl;
}

std::string ClapTrap::getName() const {
  return name;
}

unsigned int ClapTrap::getHitPoints() const {
  return hit_points;
}
unsigned int ClapTrap::getEnergyPoints() const {
  return energy_points;
}
unsigned int ClapTrap::getAttackDamage() const {
  return attack_damage;
}

void ClapTrap::setHitPoints(unsigned int n) {
  hit_points = n;
}

void ClapTrap::setEnergyPoints(unsigned int n) {
  energy_points = n;
}

void ClapTrap::setAttackDamage(unsigned int n) {
  attack_damage = n;
}

unsigned int ClapTrap::reduceHitPoints(unsigned int n) {
  if (n >= hit_points) {
    hit_points = 0;
  } else {
    hit_points -= n;
  }
  return hit_points;
}

unsigned int ClapTrap::increaseHitPoints(unsigned int n) {
  if (n >= std::numeric_limits<unsigned int>::max() - hit_points) {
    hit_points = std::numeric_limits<unsigned int>::max();
  } else {
    hit_points += n;
  }
  return hit_points;
}

unsigned int ClapTrap::reduceEnergyPoints(unsigned int n) {
  if (n >= energy_points) {
    energy_points = 0;
  } else {
    energy_points -= n;
  }
  return energy_points;
}

void ClapTrap::attack(const std::string& target) {
  if (getHitPoints() == 0) {
    std::cout << "ClapTrap " << getName() << " cannot attack " << target
              << ". It's broken." << std::endl;
  } else if (getEnergyPoints() == 0) {
    std::cout << "ClapTrap " << getName() << " cannot attack " << target
              << ". It's out of energy." << std::endl;
  } else {
    std::cout << "ClapTrap " << getName() << " attacks " << target
              << ", causing " << getAttackDamage() << " points of "
              << "damage!" << std::endl;
    reduceEnergyPoints(1);
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (getHitPoints() == 0) {
    std::cout << "Stop attacking ClapTrap " << getName()
              << " it's already broken!" << std::endl;
  } else {
    std::cout << "ClapTrap " << getName() << " took " << amount
              << " points of damage!" << std::endl;
    if (reduceHitPoints(amount) == 0) {
      std::cout << "ClapTrap " << getName() << " is out of service."
                << std::endl;
    }
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (getHitPoints() == 0) {
    std::cout << "ClapTrap " << getName() << " cannot be repaired."
              << std::endl;
  } else if (getEnergyPoints() == 0) {
    std::cout << "ClapTrap " << getName()
              << " doesn't have enough energy to repair itself." << std::endl;
  } else {
    std::cout << "ClapTrap " << getName() << " repaired itself." << std::endl;
    increaseHitPoints(amount);
    reduceEnergyPoints(1);
  }
}
