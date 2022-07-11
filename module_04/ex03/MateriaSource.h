#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "AMateria.h"
#include "IMaterialSource.h"

#define MATERIA_SIZE 4

class MateriaSource : public IMateriaSource {
  AMateria* learned_[MATERIA_SIZE];

public:
  MateriaSource();
  MateriaSource(const MateriaSource& other);

  ~MateriaSource();

  MateriaSource& operator=(const MateriaSource& other);

  virtual void LearnMateria(AMateria* materia);
  virtual AMateria* CreateMateria(std::string const& type);
};

#endif
