#include <iostream>
#include <new>
#include <string>
#include "Animal.h"
#include "Brain.h"
#include "Cat.h"
#include "Dog.h"

void print_header(const std::string& title) {
  std::cout << std::endl;
  std::cout << std::string(5, '#') << " " << title << " " << std::string(5, '#')
            << std::endl;
}

int main(void) {
  {
    print_header("BASIC TEST");

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;
  }
  {
    print_header("LOOP TEST");

    const int n = 4;
    Animal* animals[n];

    for (int i = 0; i < n; ++i) {
      if (i < n / 2) {
        animals[i] = new Cat;
      } else {
        animals[i] = new Dog;
      }
    }

    for (int i = 0; i < n; ++i) {
      delete animals[i];
    }
  }
  {
    print_header("COPY CONSTRUCTOR");

    Animal* a = new Animal();
    Animal* b = new Animal(*a);

    std::string const* a_ideas = a->getBrain()->getIdeas();
    std::string const* b_ideas = b->getBrain()->getIdeas();

    for (int i = 0; i < IDEAS_N; ++i) {
      if (a_ideas[i] != b_ideas[i] || &a_ideas[i] == &b_ideas[i]) {
        std::cout << &a_ideas[i] << std::endl;
        std::cout << &b_ideas[i] << std::endl;
        std::cout << "error: not a deep copy" << std::endl;
      }
    }
    delete a;
    delete b;
  }
  {
    print_header("COPY OPERATOR");

    Animal a;
    Animal b;
    b = a;

    std::string const* a_ideas = a.getBrain()->getIdeas();
    std::string const* b_ideas = b.getBrain()->getIdeas();

    for (int i = 0; i < IDEAS_N; ++i) {
      if (a_ideas[i] != b_ideas[i] || &a_ideas[i] == &b_ideas[i]) {
        std::cout << &a_ideas[i] << std::endl;
        std::cout << &b_ideas[i] << std::endl;
        std::cout << "error: not a deep copy" << std::endl;
      }
    }
  }
}
