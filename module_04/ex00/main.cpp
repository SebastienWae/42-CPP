#include <iostream>
#include <string>

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

void print_header(const std::string& title) {
  std::cout << std::endl;
  std::cout << std::string(5, '#') << " " << title << " " << std::string(5, '#') << std::endl;
}

int main(void) {
  {
    print_header("ANIMAL");

    Animal meta;
    Animal copy(meta);
    Animal assign;
    assign = copy;

    Animal* ptr = new Animal;
    delete ptr;

    std::cout << "type: " << meta.getType() << std::endl;
    std::cout << "sound: ";
    meta.makeSound();
  }
  {
    print_header("CAT");

    Cat cat;
    Cat copy(cat);
    Cat assign;
    assign = copy;

    Cat* ptr = new Cat;
    delete ptr;

    std::cout << "type: " << cat.getType() << std::endl;
    std::cout << "sound: ";
    cat.makeSound();
  }
  {
    print_header("DOG");

    Dog dog;
    Dog copy(dog);
    Dog assign;
    assign = copy;

    Dog* ptr = new Dog;
    delete ptr;

    std::cout << "type: " << dog.getType() << std::endl;
    std::cout << "sound: ";
    dog.makeSound();
  }
  {
    print_header("WRONG ANIMAL");

    WrongAnimal wrong;
    WrongAnimal copy(wrong);
    WrongAnimal assign;
    assign = copy;

    WrongAnimal* ptr = new WrongAnimal;
    delete ptr;

    std::cout << "type: " << wrong.getType() << std::endl;
    std::cout << "sound: ";
    wrong.makeSound();
  }
  {
    print_header("WRONG CAT");

    WrongCat cow;
    WrongCat copy(cow);
    WrongCat assign;
    assign = copy;

    WrongCat* ptr = new WrongCat;
    delete ptr;

    std::cout << "type: " << cow.getType() << std::endl;
    std::cout << "sound: ";
    cow.makeSound();
  }
}
