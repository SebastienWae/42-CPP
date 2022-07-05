#include "Zombie.h"

#define ZOMBIES 5

int main(void) {
  Zombie* horde = zombieHorde(ZOMBIES, "z");
  for (int i = 0; i < ZOMBIES; ++i) {
    horde[i].announce();
  }
  delete[] horde;
}
