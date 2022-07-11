#ifndef CURE_H
#define CURE_H

#include "AMateria.h"

class Cure : public AMateria {
public:
  Cure();
  Cure(const Cure& other);

  Cure& operator=(const Cure& other);

  ~Cure();

  virtual Cure* Clone() const;
  virtual void Use(ICharacter& target);
};

#endif
