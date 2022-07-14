#include <iostream>
#include <string>

#include "Zombie.h"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void) {
  Zombie stackZombie;
  Zombie* heapZombie;

  stackZombie.announce();
  stackZombie.setName("stack zombie");
  stackZombie.announce();

  randomChump("random chump");

  heapZombie = newZombie("heap zombie");
  heapZombie->announce();

  delete heapZombie;
}
