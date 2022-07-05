#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {
  std::string name;

 public:
  void announce(void);
  void SetName(std::string name);

  Zombie();
  Zombie(std::string name);
  ~Zombie();
};

Zombie* zombieHorde(int N, std::string name);

#endif
