#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <sstream>
#include <string>

class ClapTrap {
private:
  std::string name;
  unsigned int hit_points, energy_points, attack_damage;

public:
  ClapTrap();
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap& other);

  ClapTrap& operator=(const ClapTrap& other);

  ~ClapTrap();

  std::string getName() const;

  unsigned int reduceHitPoints(unsigned int n);
  unsigned int increaseHitPoints(unsigned int n);
  unsigned int reduceEnergyPoints(unsigned int n);

  void printStatus() const;

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif
