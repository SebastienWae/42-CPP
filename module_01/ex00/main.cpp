#include "Zombie.h"

int main(void) {
  Zombie* zombie = NewZombie("z1");
  zombie->Announce();
  delete zombie;
  RandomChump("chump");
}
