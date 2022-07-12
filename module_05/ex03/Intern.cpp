#include "Intern.h"

#include <string>

#include "Form.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

Intern::Intern() {}

Intern::Intern(const Intern& other) { (void)other; }

Intern& Intern::operator=(const Intern& other) {
  (void)other;
  return *this;
}

Intern::~Intern() {}

Form* Intern::makeForm(std::string form, std::string target) const {}
