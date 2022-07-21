#include "PresidentialPardonForm.h"

#include <iostream>

#include "Form.h"

PresidentialPardonForm::PresidentialPardonForm()
    : Form("Presidential Pardon", PRESIDENTIAL_SIGN, PRESIDENTIAL_EXEC) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : Form("Presidential Pardon", PRESIDENTIAL_SIGN, PRESIDENTIAL_EXEC), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& other)
    : Form(other), target(other.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& other) {
  Form::operator=(other);
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
    throw(GradeTooLowException, FormNotSignedException) {
  Form::execute(executor);
  std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
