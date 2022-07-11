#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <sstream>
#include <string>

#define SSTR(x) static_cast<std::ostringstream&>((std::ostringstream() << std::dec << x)).str()

class ClapTrap {
protected:
  std::string name;
  unsigned int hit_points, energy_points, attack_damage;

public:
  ClapTrap();
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap& other);

  ClapTrap& operator=(const ClapTrap& other);

  ~ClapTrap();

  std::string GetName() const;

  unsigned int ReduceHitPoints(unsigned int n);
  unsigned int IncreaseHitPoints(unsigned int n);
  unsigned int ReduceEnergyPoints(unsigned int n);

  virtual void Log(const std::string& type, const std::string& msg);
  void PrintStatus() const;

  virtual void Attack(const std::string& target);
  void TakeDamage(unsigned int amount);
  void BeRepaired(unsigned int amount);
};

#endif
