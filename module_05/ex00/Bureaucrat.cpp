#include "Bureaucrat.h"

#include <iostream>

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

std::string Bureaucrat::getName() const { return name; }

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
  std::string const displayName = (b.getName().empty()) ? "<no-name>" : b.getName();
  os << displayName << ", bureaucrat grade " << b.getGrade() << ".";
  return os;
}
