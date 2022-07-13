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
  name = other.name;
  grade = other.grade;
  return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return name.empty() ? "<no-name>" : name; }

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

char const* Bureaucrat::GradeTooHighException::what() const throw() { return exception::what(); }

char const* Bureaucrat::GradeTooLowException::what() const throw() { return exception::what(); }

std::ostream& operator<<(std::ostream& os, Bureaucrat const& b) {
  std::string const display_name = (b.getName().empty()) ? "<no-name>" : b.getName();
  os << display_name << ", bureaucrat grade " << b.getGrade() << ".";
  return os;
}

void Bureaucrat::signForm(Form& form) {
  try {
    if (form.beSigned(this)) {
      std::cout << getName() << " signed " << form.getName() << std::endl;
    } else {
      std::cout << getName() << " couldn’t sign " << form.getName()
                << " because his grade is too low." << std::endl;
    }
  } catch (GradeTooLowException& e) {
    std::cout << getName() << " couldn’t sign " << form.getName()
              << " because his grade is too low." << std::endl;
  }
}

void Bureaucrat::executeForm(Form const& form) const {
  if (form.execute(*this)) {
    std::cout << getName() << " executed " << form.getName() << std::endl;
  } else {
    std::cout << "form: " << form.getName() << " was not executed by " << getName()
              << " because it is not signed." << std::endl;
  }
}
