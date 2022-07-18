#include "Cure.h"

#include <iostream>

#include "ICharacter.h"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const& other) : AMateria(other) {}

Cure::~Cure() {}

Cure* Cure::clone() const { return new Cure; }

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
