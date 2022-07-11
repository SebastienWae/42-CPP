#include <string>

#include "Zombie.h"

Zombie* ZombieHorde(int N, std::string name) {
  Zombie* horde = new Zombie[N];
  for (int i = 0; i < N; ++i) {
    horde[i].SetName(name);
  }
  return horde;
}
