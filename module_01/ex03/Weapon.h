#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
  std::string type_;

public:
  const std::string& GetType() const;
  void SetType(std::string new_type);

  Weapon(std::string type);
};

#endif
