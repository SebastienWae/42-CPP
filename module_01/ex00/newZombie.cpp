#include <string>

#include "Zombie.h"

Zombie* NewZombie(std::string name) {
  Zombie* zombie = new Zombie(name);
  return zombie;
}
