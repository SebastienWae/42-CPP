#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <ostream>
#include <string>

#define MIN_GRADE 150
#define MAX_GRADE 1

class Bureaucrat {
  std::string const name;
  int grade;

public:
  class GradeTooHighException : public std::exception {
  public:
    virtual char const* what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual char const* what() const throw();
  };

  Bureaucrat();
  Bureaucrat(std::string name, int grade) throw(GradeTooHighException, GradeTooLowException);
  Bureaucrat(Bureaucrat const& other);

  Bureaucrat& operator=(Bureaucrat const& other);

  ~Bureaucrat();

  std::string getName() const;
  int getGrade() const;

  void incrementGrade() throw(GradeTooHighException);
  void decrementGrade() throw(GradeTooLowException);
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& b);

#endif
