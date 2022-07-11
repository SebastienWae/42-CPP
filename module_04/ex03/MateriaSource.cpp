#include "MateriaSource.h"

#include <iostream>

#include "AMateria.h"

MateriaSource::MateriaSource() {
  for (int i = 0; i < MATERIA_SIZE; ++i) {
    learned_[i] = NULL;
  }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
  for (int i = 0; i < MATERIA_SIZE; ++i) {
    AMateria* item = other.learned_[i];
    if (item != NULL) {
      learned_[i] = item->Clone();
    } else {
      learned_[i] = NULL;
    }
  }
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < MATERIA_SIZE; ++i) {
    AMateria* item = learned_[i];
    if (item != NULL) {
      delete item;
    }
  }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
  if (this == &other) {
    return *this;
  }

  for (int i = 0; i < MATERIA_SIZE; ++i) {
    AMateria* item = learned_[i];
    if (item != NULL) {
      delete item;
    }
    item = other.learned_[i];
    if (item != NULL) {
      learned_[i] = item->Clone();
    } else {
      learned_[i] = NULL;
    }
  }
  return *this;
}

void MateriaSource::LearnMateria(AMateria* materia) {
  for (int i = 0; i < MATERIA_SIZE; ++i) {
    if (learned_[i] == NULL) {
      std::cout << "new materia learned: " << materia->GetType() << std::endl;
      learned_[i] = materia;
      return;
    }
  }
  std::cout << "materia source is full" << std::endl;
}

AMateria* MateriaSource::CreateMateria(std::string const& type) {
  for (int i = 0; i < MATERIA_SIZE; ++i) {
    AMateria* item = learned_[i];
    if (item != NULL && item->GetType() == type) {
      std::cout << "new materia created: " << item->GetType() << std::endl;
      return item->Clone();
    }
  }
  std::cout << type << " is not a known materia" << std::endl;
  return NULL;
}
