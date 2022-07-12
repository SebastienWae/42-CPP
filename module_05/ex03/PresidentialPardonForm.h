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

  PresidentialPardonForm(const PresidentialPardonForm& other);

  PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

  ~PresidentialPardonForm();

  virtual bool execute(Bureaucrat const& executor) const;
};

#endif
