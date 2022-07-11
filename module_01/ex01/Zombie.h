#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {
  std::string name_;

public:
  void Announce(void);
  void SetName(std::string name);

  Zombie();
  Zombie(std::string name);
  ~Zombie();
};

Zombie* ZombieHorde(int N, std::string name);

#endif
