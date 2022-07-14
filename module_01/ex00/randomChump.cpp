#include <string>

#include "Zombie.h"

void randomChump(std::string name) {
  Zombie chump = Zombie(name);
  chump.announce();
}
