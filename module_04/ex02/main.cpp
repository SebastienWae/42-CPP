#include <iostream>
#include <new>
#include <string>
#include "Animal.h"
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

    Dog dog;
    Cat cat;

    dog.makeSound();
    cat.makeSound();
  }
  // { Animal meta; }
}
