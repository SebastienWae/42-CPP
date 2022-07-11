#include "Cure.h"

#include <iostream>

#include "ICharacter.h"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& other) : AMateria(other) {}

Cure::~Cure() {}

Cure* Cure::Clone() const { return new Cure; }

void Cure::Use(ICharacter& target) {
  std::cout << "* heals " << target.GetName() << "’s wounds *" << std::endl;
}
