#include <iostream>

#include "Bureaucrat.h"

int main(void) {
  {
    try {
      std::cout << "## TEST 1" << std::endl;
      Bureaucrat a = Bureaucrat("a", 1);

      std::cout << a << std::endl;
      a.decrementGrade();
      std::cout << a << std::endl;
      a.incrementGrade();
      std::cout << a << std::endl;
      a.incrementGrade();
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    try {
      std::cout << "## TEST 2" << std::endl;
      Bureaucrat a = Bureaucrat("a", 150);

      std::cout << a << std::endl;
      a.incrementGrade();
      std::cout << a << std::endl;
      a.decrementGrade();
      std::cout << a << std::endl;
      a.decrementGrade();
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    try {
      std::cout << "## TEST 3" << std::endl;
      Bureaucrat a = Bureaucrat("a", 0);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    try {
      std::cout << "## TEST 4" << std::endl;
      Bureaucrat a = Bureaucrat("a", 151);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
}
