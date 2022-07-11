#ifndef IMATERIALSOURCE_H
#define IMATERIALSOURCE_H

#include "AMateria.h"

class IMateriaSource {
public:
  virtual ~IMateriaSource() {}
  virtual void LearnMateria(AMateria*) = 0;
  virtual AMateria* CreateMateria(std::string const& type) = 0;
};

#endif
