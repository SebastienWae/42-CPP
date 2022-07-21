#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "Form.h"

#define SHRUBBERY_SIGN 145
#define SHRUBBERY_EXEC 137

class ShrubberyCreationForm : public Form {
  std::string target;

public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(std::string target);

  ShrubberyCreationForm(ShrubberyCreationForm const& other);

  ShrubberyCreationForm& operator=(ShrubberyCreationForm const& other);

  ~ShrubberyCreationForm();

  virtual void execute(Bureaucrat const& executor) const
      throw(GradeTooLowException, FormNotSignedException);
};

#endif
