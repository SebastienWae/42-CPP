#include "Zombie.h"

#include <iostream>

Zombie::Zombie() {}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie() { std::cout << "Zombie Destructor called for " << name << std::endl; }

void Zombie::announce() const { std::cout << name << ": BraiiiiiiinnnzzzZ" << std::endl; }

void Zombie::setName(std::string name) { this->name = name; }
