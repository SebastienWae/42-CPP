#include <string>

#include "Zombie.h"

void RandomChump(std::string name) {
  Zombie zombie = Zombie(name);
  zombie.Announce();
}
