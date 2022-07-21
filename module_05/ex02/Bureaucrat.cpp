#include "Bureaucrat.h"

#include <iostream>

#include "Form.h"

Bureaucrat::Bureaucrat() : grade(MIN_GRADE) {}

Bureaucrat::Bureaucrat(std::string name, int grade) throw(Bureaucrat::GradeTooHighException,
                                                          Bureaucrat::GradeTooLowException)
    : name(name) {
  if (grade < MAX_GRADE) {
    throw GradeTooHighException();
  }
  if (grade > MIN_GRADE) {
    throw GradeTooLowException();
  }
  this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  grade = other.grade;
  return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return name.empty() ? "<no-name bureaucrate>" : name; }

int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::incrementGrade() throw(Bureaucrat::GradeTooHighException) {
  if (grade == MAX_GRADE) {
    throw GradeTooHighException();
  }
  grade--;
}

void Bureaucrat::decrementGrade() throw(Bureaucrat::GradeTooLowException) {
  if (grade == MIN_GRADE) {
    throw GradeTooLowException();
  }
  grade++;
}

char const* Bureaucrat::GradeTooHighException::what() const throw() { return "Grade is too high."; }

char const* Bureaucrat::GradeTooLowException::what() const throw() { return "Grade is too low."; }

std::ostream& operator<<(std::ostream& os, Bureaucrat const& b) {
  os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
  return os;
}

void Bureaucrat::signForm(Form& form) {
  try {
    if (form.beSigned(this)) {
      std::cout << getName() << " signed " << form.getName() << std::endl;
    } else {
      std::cout << "form: " << form.getName() << " is already signed." << std::endl;
    }
  } catch (Form::GradeTooLowException&) {
    std::cout << getName() << " couldn’t sign " << form.getName()
              << " because his grade is too low." << std::endl;
  }
}

void Bureaucrat::executeForm(Form const& form) const {
  try {
    form.execute(*this);
    std::cout << getName() << " executed " << form.getName() << std::endl;
  } catch (Form::GradeTooLowException&) {
    std::cout << "form: " << form.getName() << " was not executed by " << getName()
              << " because his grade is too low." << std::endl;
  } catch (Form::FormNotSignedException&) {
    std::cout << "form: " << form.getName() << " was not executed by " << getName()
              << " because it is not signed." << std::endl;
  }
}
