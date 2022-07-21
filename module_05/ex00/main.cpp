#include <iostream>

#include "Bureaucrat.h"

int main(void) {
  {
    try {
      std::cout << "## TEST 1" << std::endl;
      Bureaucrat a = Bureaucrat("a", MAX_GRADE);

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
      Bureaucrat a = Bureaucrat("a", MIN_GRADE);

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
      Bureaucrat a = Bureaucrat("a", MAX_GRADE - 1);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    try {
      std::cout << "## TEST 4" << std::endl;
      Bureaucrat a = Bureaucrat("a", MIN_GRADE + 1);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
}
