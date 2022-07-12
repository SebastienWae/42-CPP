#include "Form.h"

#include <iostream>

#include "Bureaucrat.h"

Form::Form() : is_signed(false), grade_req_sign(MIN_GRADE), grade_req_exec(MIN_GRADE) {}

Form::Form(std::string name, int grade_req_sign,
           int grade_req_exec) throw(Form::GradeTooHighException, Form::GradeTooLowException)
    : name(name), is_signed(false), grade_req_sign(grade_req_sign), grade_req_exec(grade_req_exec) {
  if (grade_req_sign < MAX_GRADE || grade_req_exec < MAX_GRADE) {
    throw GradeTooHighException();
  }
  if (grade_req_sign > MIN_GRADE || grade_req_exec > MIN_GRADE) {
    throw GradeTooLowException();
  }
}

Form::Form(const Form& other)
    : name(other.name),
      is_signed(other.is_signed),
      grade_req_sign(other.grade_req_sign),
      grade_req_exec(other.grade_req_exec) {}

Form::~Form() {}

std::string Form::getName() const { return name.empty() ? "<no-name>" : name; }

bool Form::getIsSigned() const { return is_signed; }

int Form::getGradeReqSign() const { return grade_req_sign; }

int Form::getGradeReqExec() const { return grade_req_sign; }

bool Form::beSigned(Bureaucrat* bureaucrat) throw(Form::GradeTooLowException) {
  if (bureaucrat->getGrade() > grade_req_sign) {
    throw GradeTooLowException();
  }
  if (is_signed) {
    return false;
  }
  is_signed = true;
  return true;
}

char const* Form::GradeTooHighException::what() const throw() { return exception::what(); }

char const* Form::GradeTooLowException::what() const throw() { return exception::what(); }

std::ostream& operator<<(std::ostream& os, Form& f) {
  os << "form: " << f.getName() << (f.getIsSigned() ? " is " : " is not ")
     << "signed. Requires grade " << f.getGradeReqSign() << " to sign it and "
     << f.getGradeReqExec() << " to execute it.";
  return os;
}
