#include "Zombie.h"

int main(void) {
  Zombie* zombie = newZombie("z1");
  zombie->announce();
  delete zombie;
  randomChump("chump");
}
