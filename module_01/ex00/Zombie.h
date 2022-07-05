#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {
  std::string name;

 public:
  void announce(void);

  Zombie(std::string name);
  ~Zombie();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
