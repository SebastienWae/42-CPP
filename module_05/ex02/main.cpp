#include <exception>
#include <iostream>

#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

int main(void) {
  {
    std::cout << "## TEST 1 ##" << std::endl;
    PresidentialPardonForm f("target");
    Bureaucrat a("a", MAX_GRADE);
    Bureaucrat b("b", MIN_GRADE);

    std::cout << f << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    a.signForm(f);

    std::cout << f << std::endl;

    b.executeForm(f);
  }
  {
    std::cout << "## TEST 2 ##" << std::endl;
    ShrubberyCreationForm f("target");

    Bureaucrat a("a", MAX_GRADE);

    std::cout << f << std::endl;
    std::cout << a << std::endl;

    a.executeForm(f);
  }
  {
    std::cout << "## TEST 3 ##" << std::endl;
    RobotomyRequestForm r("target");
    PresidentialPardonForm p("target");
    ShrubberyCreationForm s("ddd");
    Bureaucrat a("a", MAX_GRADE);

    std::cout << r << std::endl;
    std::cout << p << std::endl;
    std::cout << s << std::endl;
    std::cout << a << std::endl;

    a.signForm(r);
    a.signForm(p);
    a.signForm(s);

    std::cout << r << std::endl;
    std::cout << p << std::endl;
    std::cout << s << std::endl;

    a.executeForm(r);
    a.executeForm(p);
    a.executeForm(s);
  }
}
