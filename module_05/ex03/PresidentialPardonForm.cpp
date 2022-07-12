#include "PresidentialPardonForm.h"

#include <iostream>

#include "Form.h"

PresidentialPardonForm::PresidentialPardonForm()
    : Form("presidential", PRESIDENTIAL_SIGN, PRESIDENTIAL_EXEC) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : Form("presidential", PRESIDENTIAL_SIGN, PRESIDENTIAL_EXEC), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : Form(other), target(other.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
  setSigned(other.getIsSigned());
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

bool PresidentialPardonForm::execute(Bureaucrat const& executor) const {
  if (!getIsSigned()) {
    return false;
  }
  if (executor.getGrade() > getGradeReqExec()) {
    throw GradeTooLowException();
  }
  std::cout << target << "has been pardoned by Zaphod Beeblebrox" << std::endl;
  return true;
}
