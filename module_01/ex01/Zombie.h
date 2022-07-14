#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {
  std::string name;

public:
  Zombie();
  Zombie(std::string name);
  ~Zombie();

  void announce() const;

  void setName(std::string name);
};

#endif
