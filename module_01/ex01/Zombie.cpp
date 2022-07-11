#include "Zombie.h"

#include <iostream>

void Zombie::Announce() { std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl; }

void Zombie::SetName(std::string new_name) { name_ = new_name; }

Zombie::Zombie(std::string name) : name_(name) {}

Zombie::Zombie() {}

Zombie::~Zombie() { std::cout << name_ << ": dead..." << std::endl; }
