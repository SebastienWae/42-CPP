#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClapTrap {
  std::string name;
  unsigned int hit_points, energy_points, attack_damage;

 public:
  ClapTrap();
  ClapTrap(std::string name);
  ClapTrap(ClapTrap& other);

  ClapTrap& operator=(const ClapTrap& copy);

  ~ClapTrap();

  std::string getName() const;
  unsigned int getHitPoints() const;
  unsigned int getEnergyPoints() const;
  unsigned int getAttackDamage() const;

  void setHitPoints(unsigned int n);
  void setEnergyPoints(unsigned int n);
  void setAttackDamage(unsigned int n);

  unsigned int reduceHitPoints(unsigned int n);
  unsigned int increaseHitPoints(unsigned int n);
  unsigned int reduceEnergyPoints(unsigned int n);

  virtual void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif
