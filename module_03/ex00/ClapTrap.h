#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClapTrap {
  std::string name;
  unsigned int hit_points, energy_points, attack_damage;

 public:
  ClapTrap(std::string name);
  ClapTrap(ClapTrap& other);

  ClapTrap& operator=(const ClapTrap& copy);

  ~ClapTrap();

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif
