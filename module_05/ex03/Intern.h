#ifndef INTERN_H
#define INTERN_H

#include <string>

#include "Form.h"

class Intern {
public:
  Intern();
  Intern(const Intern& other);

  Intern& operator=(const Intern& other);

  ~Intern();

  Form* makeForm(std::string form, std::string target) const;
};

#endif
