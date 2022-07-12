#include "RobotomyRequestForm.h"

#include <cstdlib>
#include <iostream>

#include "Form.h"

RobotomyRequestForm::RobotomyRequestForm() : Form("robotomy", ROBOTOMY_SIGN, ROBOTOMY_EXEC) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : Form("robotomy", ROBOTOMY_EXEC, ROBOTOMY_EXEC), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : Form(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
  setSigned(other.getIsSigned());
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

bool RobotomyRequestForm::execute(Bureaucrat const& executor) const {
  if (!getIsSigned()) {
    return false;
  }
  if (executor.getGrade() > getGradeReqExec()) {
    throw GradeTooLowException();
  }
  std::cout << "* drilling noises *" << std::endl;
  if ((std::rand() % 2) != 0) {
    std::cout << target << " has been robotomized" << std::endl;
  } else {
    std::cout << "robotomy has failed!" << std::endl;
  }
  return true;
}
