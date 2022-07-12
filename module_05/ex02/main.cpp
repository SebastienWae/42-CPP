#include <exception>
#include <iostream>

#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

int main(void) {
  {
    std::cout << "## TEST 1 ##" << std::endl;
    try {
      PresidentialPardonForm f("t1");
      Bureaucrat b("steve", 150);
      f.setSigned(true);
      b.executeForm(f);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    std::cout << "## TEST 2 ##" << std::endl;
    try {
      PresidentialPardonForm f("t1");
      Bureaucrat b("steve", 1);
      b.executeForm(f);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    std::cout << "## TEST 3 ##" << std::endl;
    try {
      RobotomyRequestForm r("r1");
      PresidentialPardonForm f("t1");
      ShrubberyCreationForm s("s1");
      Bureaucrat b("steve", 1);

      b.signForm(&r);
      b.signForm(&f);
      b.signForm(&s);

      b.executeForm(r);
      b.executeForm(f);
      b.executeForm(s);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
}
