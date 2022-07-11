#ifndef CLAPTRAP_20COPY_H
#define CLAPTRAP_20COPY_H
#ifndef CLAPTRAP_H
#  define CLAPTRAP_H

#  include <sstream>
#  include <string>

#  define SSTR(x) static_cast<std::ostringstream&>((std::ostringstream() << std::dec << x)).str()

class ClapTrap {
  std::string name_;
  unsigned int hit_points, energy_points, attack_damage;

public:
  ClapTrap();
  ClapTrap(std::string name);
  ClapTrap(ClapTrap& other);

  ClapTrap& operator=(const ClapTrap& copy);

  ~ClapTrap();

  virtual std::string getName() const;
  unsigned int getHitPoints() const;
  unsigned int getEnergyPoints() const;
  unsigned int getAttackDamage() const;

  void setName(std::string new_name);
  void setHitPoints(unsigned int n);
  void setEnergyPoints(unsigned int n);
  void setAttackDamage(unsigned int n);

  unsigned int reduceHitPoints(unsigned int n);
  unsigned int increaseHitPoints(unsigned int n);
  unsigned int reduceEnergyPoints(unsigned int n);

  virtual std::string getTypeName() const;
  void log(const std::string& msg) const;
  void printStatus() const;

  virtual void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif

#endif
