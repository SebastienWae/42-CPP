#include <string>

#include "Zombie.h"

Zombie* zombieHorde(int n, std::string name) {
  Zombie* horde = NULL;

  if (n <= 0) {
    return horde;
  }
  horde = new Zombie[n];
  for (int i = 0; i < n; i++) {
    horde[i].setName(name);
  }

  return horde;
}
