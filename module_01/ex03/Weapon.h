#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
  std::string type;

 public:
  const std::string& getType() const;
  void setType(std::string new_type);

  Weapon(std::string type);
};

#endif
