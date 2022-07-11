#include "Zombie.h"

#define ZOMBIES 5

int main(void) {
  Zombie* horde = ZombieHorde(ZOMBIES, "z");
  for (int i = 0; i < ZOMBIES; ++i) {
    horde[i].Announce();
  }
  delete[] horde;
}
