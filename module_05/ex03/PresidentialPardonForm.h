#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "Form.h"

#define PRESIDENTIAL_SIGN 25
#define PRESIDENTIAL_EXEC 5

class PresidentialPardonForm : public Form {
  std::string target;

public:
  PresidentialPardonForm();
  PresidentialPardonForm(std::string target);

  PresidentialPardonForm(PresidentialPardonForm const& other);

  PresidentialPardonForm& operator=(PresidentialPardonForm const& other);

  ~PresidentialPardonForm();

  virtual void execute(Bureaucrat const& executor) const
      throw(GradeTooLowException, FormNotSignedException);
};

#endif
