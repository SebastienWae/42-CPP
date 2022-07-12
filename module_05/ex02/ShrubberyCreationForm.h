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

  ShrubberyCreationForm(const ShrubberyCreationForm& other);

  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

  ~ShrubberyCreationForm();

  virtual bool execute(Bureaucrat const& executor) const;
};

#endif
