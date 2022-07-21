#include "Intern.h"

#include <iostream>
#include <string>

#include "Form.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

Intern::FormCustructor Intern::formConstructors[3]
    = {Intern::create<PresidentialPardonForm>, Intern::create<RobotomyRequestForm>,
       Intern::create<ShrubberyCreationForm>};
std::string Intern::formTypes[3]
    = {"presidential pardon", "robotomy request", "shrubbery creation"};

Intern::Intern() {}

Intern::Intern(const Intern& other) { (void)other; }

Intern& Intern::operator=(const Intern& other) {
  (void)other;
  return *this;
}

Intern::~Intern() {}

Form* Intern::makeForm(std::string form, std::string target) const {
  Form* new_form = NULL;
  for (int i = 0; i < 3; ++i) {
    if (formTypes[i] == form) {
      new_form = formConstructors[i](target);
    }
  }
  if (new_form != 0) {
    std::cout << "The intern created a new '" << form << "' form" << std::endl;
    return new_form;
  }
  std::cout << "This type of form does not exist" << std::endl;
  return NULL;
}
