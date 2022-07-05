#include "Zombie.h"

#include <iostream>

void Zombie::announce() {
  std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie() { std::cout << name << ": dead..." << std::endl; }
