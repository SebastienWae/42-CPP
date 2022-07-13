#ifndef FORM_H
#define FORM_H

#include <string>

#include "Bureaucrat.h"

class Form {
  const std::string name;
  bool is_signed;
  const int grade_req_sign;
  const int grade_req_exec;

public:
  class GradeTooHighException : public std::exception {
  public:
    virtual char const* what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual char const* what() const throw();
  };

  Form();
  Form(std::string name, int grade_req_sign, int grade_req_exec) throw(GradeTooHighException,
                                                                       GradeTooLowException);
  Form(const Form& other);

  Form& operator=(const Form& other);

  virtual ~Form();

  std::string getName() const;
  bool getIsSigned() const;
  int getGradeReqSign() const;
  int getGradeReqExec() const;

  void setSigned(bool b);

  bool beSigned(Bureaucrat* bureaucrat) throw(GradeTooLowException);

  virtual bool execute(Bureaucrat const& executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, Form& f);

#endif
