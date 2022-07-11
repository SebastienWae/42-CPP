#include "ClapTrap.h"

#include <iostream>
#include <limits>
#include <string>
#include <typeinfo>

ClapTrap::ClapTrap() : hit_points(10), energy_points(10), attack_damage(0) {
  log("default constructor");
}

ClapTrap::ClapTrap(std::string n)
    : name_(name_), hit_points(10), energy_points(10), attack_damage(0) {
  log("name constructor");
}

ClapTrap::ClapTrap(ClapTrap& other)
    : name_(other.getName()),
      hit_points(other.getEnergyPoints()),
      energy_points(other.getEnergyPoints()),
      attack_damage(other.getAttackDamage()) {
  log("copy constructor");
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy) {
  setName(copy.getName());
  setHitPoints(copy.getHitPoints());
  setEnergyPoints(copy.getHitPoints());
  setAttackDamage(copy.getAttackDamage());
  log("copy operator");
  return *this;
}

ClapTrap::~ClapTrap() { log("destructor"); }

std::string ClapTrap::getName() const { return name_; }

unsigned int ClapTrap::getHitPoints() const { return hit_points; }

unsigned int ClapTrap::getEnergyPoints() const { return energy_points; }

unsigned int ClapTrap::getAttackDamage() const { return attack_damage; }

void ClapTrap::setName(std::string new_name) { name_ = new_name; }

void ClapTrap::setHitPoints(unsigned int n) { hit_points = n; }

void ClapTrap::setEnergyPoints(unsigned int n) { energy_points = n; }

void ClapTrap::setAttackDamage(unsigned int n) { attack_damage = n; }

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

std::string ClapTrap::getTypeName() const { return "ClapTrap"; }

void ClapTrap::log(const std::string& msg) const {
  std::cout << getTypeName() << " '" << getName() << "': " << msg << std::endl;
}

void ClapTrap::printStatus() const {
  std::cout << "### " << getName() << " STATUS ###" << std::endl;
  std::cout << "hit points: " << getHitPoints() << std::endl;
  std::cout << "energy points: " << getEnergyPoints() << std::endl;
  std::cout << "attack damage: " << getAttackDamage() << std::endl;
  std::cout << "type: " << getTypeName() << std::endl;
  std::cout << "address: " << this << std::endl;
}

void ClapTrap::attack(const std::string& target) {
  if (getHitPoints() == 0) {
    log("cannot attack. No hit points left");
  } else if (getEnergyPoints() == 0) {
    log("cannot attack. No energy points left");
  } else {
    log("dealt " + SSTR(getAttackDamage()) + " of damage to " + target);
    reduceEnergyPoints(1);
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (getHitPoints() == 0) {
    log("is out of service");
  } else {
    amount = reduceHitPoints(amount);
    log("took " + SSTR(amount) + " of damage");
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (getHitPoints() == 0) {
    log("cannot be repaired. It's out of service");
  } else if (getEnergyPoints() == 0) {
    log("cannot be repaired. Not enough energy points");
  } else {
    amount = increaseHitPoints(amount);
    reduceEnergyPoints(1);
    log("was repaired. It gained " + SSTR(amount) + " hit points");
  }
}
