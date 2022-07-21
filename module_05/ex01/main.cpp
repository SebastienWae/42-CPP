#include <iostream>

#include "Bureaucrat.h"
#include "Form.h"

int main(void) {
  {
    try {
      std::cout << "## TEST 1" << std::endl;
      Form f("asdf", MIN_GRADE + 1, MAX_GRADE);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    try {
      std::cout << "## TEST 2" << std::endl;
      Form f = Form("form 1", MIN_GRADE, MAX_GRADE - 1);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    try {
      std::cout << "## TEST 3" << std::endl;
      Form f = Form("form 1", MAX_GRADE, MIN_GRADE);
      Bureaucrat b = Bureaucrat("b 1", 50);

      std::cout << f << std::endl;
      std::cout << b << std::endl;
      b.signForm(f);

    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    try {
      std::cout << "## TEST 4" << std::endl;
      Form f = Form("form 1", MIN_GRADE, MIN_GRADE);
      Bureaucrat b = Bureaucrat("b 1", 50);

      std::cout << f << std::endl;
      std::cout << b << std::endl;
      b.signForm(f);

      std::cout << f << std::endl;

    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
}
