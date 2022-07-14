#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
  std::string type;

public:
  Weapon(std::string type);
  ~Weapon();

  std::string const& getType() const;
  void setType(std::string type);
};

#endif
