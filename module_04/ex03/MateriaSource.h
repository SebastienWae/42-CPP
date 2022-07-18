#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "AMateria.h"
#include "IMaterialSource.h"

#define MATERIA_SIZE 4

class MateriaSource : public IMateriaSource {
  AMateria* learned_[MATERIA_SIZE];

public:
  MateriaSource();
  MateriaSource(MateriaSource const& other);

  ~MateriaSource();

  MateriaSource& operator=(MateriaSource const& other);

  virtual void learnMateria(AMateria* materia);
  virtual AMateria* createMateria(std::string const& type);
};

#endif
