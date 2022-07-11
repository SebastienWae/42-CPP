#include "Zombie.h"

#include <iostream>

void Zombie::Announce() { std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl; }

Zombie::Zombie(std::string name) : name_(name) {}

Zombie::~Zombie() { std::cout << name_ << ": dead..." << std::endl; }
