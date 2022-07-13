#include <cstdlib>
#include <iostream>
#include <typeinfo>

#include "A.h"
#include "B.h"
#include "Base.h"
#include "C.h"

Base* generate(void) {
  int i = std::rand() % 3;

  switch (i) {
    case 0:
      return new A;
    case 1:
      return new B;
    default:
      return new C;
  }
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p) != 0) {
    std::cout << "A class" << std::endl;
  }
  if (dynamic_cast<B*>(p) != 0) {
    std::cout << "B class" << std::endl;
  }
  if (dynamic_cast<C*>(p) != 0) {
    std::cout << "C class" << std::endl;
  }
}

void identify(Base& p) {
  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "A class" << std::endl;
  } catch (std::bad_cast) {
  }
  try {
    (void)dynamic_cast<B&>(p);
    std::cout << "B class" << std::endl;
  } catch (std::bad_cast) {
  }
  try {
    (void)dynamic_cast<C&>(p);
    std::cout << "C class" << std::endl;
  } catch (std::bad_cast) {
  }
}

int main(void) {
  srand(time(NULL));
  Base* one = generate();
  Base* two = generate();
  Base* three = generate();
  Base* four = generate();

  identify(one);
  identify(two);
  identify(three);
  identify(four);

  identify(*one);
  identify(*two);
  identify(*three);
  identify(*four);
}
