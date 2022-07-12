#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "Form.h"

#define ROBOTOMY_SIGN 72
#define ROBOTOMY_EXEC 45

class RobotomyRequestForm : public Form {
  std::string target;

public:
  RobotomyRequestForm();
  RobotomyRequestForm(std::string target);

  RobotomyRequestForm(const RobotomyRequestForm& other);

  RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

  ~RobotomyRequestForm();

  virtual bool execute(Bureaucrat const& executor) const;
};

#endif
