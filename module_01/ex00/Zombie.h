#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {
  std::string name_;

public:
  Zombie(std::string name);

  ~Zombie();

  void Announce(void);
};

Zombie* NewZombie(std::string name);
void RandomChump(std::string name);

#endif
