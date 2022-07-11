#include "Ice.h"

#include <iostream>

#include "ICharacter.h"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& other) : AMateria(other) {}

Ice::~Ice() {}

Ice* Ice::Clone() const { return new Ice; }

void Ice::Use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.GetName() << " *" << std::endl;
}
