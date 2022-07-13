#include "Intern.h"

#include <iostream>
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

Form* Intern::makeForm(std::string form, std::string target) const {
  std::string typesForm[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
  int num_type = 0;

  while (form != typesForm[num_type] && num_type < 3) {
    num_type++;
  }

  switch (num_type) {
    case 0:
      return (new ShrubberyCreationForm(target));
    case 1:
      return (new RobotomyRequestForm(target));
    case 2:
      return (new PresidentialPardonForm(target));
    default:
      std::cout << "This type of form does not exist." << std::endl;
      return NULL;
  }
}
