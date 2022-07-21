#include "RobotomyRequestForm.h"

#include <cstdlib>
#include <iostream>

#include "Form.h"

RobotomyRequestForm::RobotomyRequestForm()
    : Form("Robotomy Request", ROBOTOMY_SIGN, ROBOTOMY_EXEC) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : Form("Robotomy Request", ROBOTOMY_EXEC, ROBOTOMY_EXEC), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& other)
    : Form(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& other) {
  Form::operator=(other);
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
    throw(GradeTooLowException, FormNotSignedException) {
  Form::execute(executor);
  std::cout << "* drilling noises *" << std::endl;
  srand(time(NULL));
  if ((std::rand() % 2) != 0) {
    std::cout << target << " has been robotomized" << std::endl;
  } else {
    std::cout << "robotomy has failed!" << std::endl;
  }
}
