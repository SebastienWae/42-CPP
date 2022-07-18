#ifndef CURE_H
#define CURE_H

#include "AMateria.h"

class Cure : public AMateria {
public:
  Cure();
  Cure(Cure const& other);

  Cure& operator=(Cure const& other);

  ~Cure();

  virtual Cure* clone() const;
  virtual void use(ICharacter& target);
};

#endif
