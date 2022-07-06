#include "Zombie.h"

#include <iostream>

void Zombie::announce() {
  std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::SetName(std::string new_name) {
  name = new_name;
}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::Zombie() {}

Zombie::~Zombie() {
  std::cout << name << ": dead..." << std::endl;
}
