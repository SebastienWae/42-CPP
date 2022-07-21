#include <iostream>

#include "Bureaucrat.h"
#include "Intern.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

int main(void) {
  {
    std::cout << "## TEST 1 ##" << std::endl;

    Intern intern;

    intern.makeForm("", "me");
    intern.makeForm("abdsfsd", "me");
    intern.makeForm("creation shrubbery", "home");
  }
  {
    std::cout << "## TEST 2 ##" << std::endl;

    Intern intern;
    Bureaucrat bureaucrate("Steve", MAX_GRADE);
    Form* form;

    form = intern.makeForm("robotomy request", "Bender");
    bureaucrate.signForm(*form);
    bureaucrate.executeForm(*form);
    delete form;

    form = intern.makeForm("presidential pardon", "Bender");
    bureaucrate.signForm(*form);
    bureaucrate.executeForm(*form);
    delete form;

    form = intern.makeForm("shrubbery creation", "home");
    bureaucrate.signForm(*form);
    bureaucrate.executeForm(*form);
    delete form;
  }
}
