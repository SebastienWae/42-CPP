#ifndef INTERN_H
#define INTERN_H

#include <string>

#include "Form.h"

class Intern {
  typedef Form* (*FormCustructor)(std::string);
  template <class T> static Form* create(std::string target) { return new T(target); }
  static FormCustructor formConstructors[3];
  static std::string formTypes[3];

public:
  Intern();
  Intern(const Intern& other);

  Intern& operator=(const Intern& other);

  ~Intern();

  Form* makeForm(std::string form, std::string target) const;
};

#endif
