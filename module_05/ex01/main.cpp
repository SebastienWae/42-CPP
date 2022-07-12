#include <iostream>

#include "Bureaucrat.h"
#include "Form.h"

int main(void) {
  {
    try {
      std::cout << "## TEST 1" << std::endl;
      Form f("asdf", 151, 1);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    try {
      std::cout << "## TEST 2" << std::endl;
      Form f = Form("form 1", 150, 0);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    try {
      std::cout << "## TEST 3" << std::endl;
      Form f = Form("form 1", 1, 150);
      Bureaucrat b = Bureaucrat("b 1", 50);

      std::cout << f << std::endl;
      std::cout << b << std::endl;
      b.signForm(&f);

    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    try {
      std::cout << "## TEST 4" << std::endl;
      Form f = Form("form 1", 150, 150);
      Bureaucrat b = Bureaucrat("b 1", 50);

      std::cout << f << std::endl;
      std::cout << b << std::endl;
      b.signForm(&f);

      std::cout << f;

    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
}
