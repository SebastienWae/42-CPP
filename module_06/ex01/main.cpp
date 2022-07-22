#include <stdint.h>

#include <iostream>

#include "Data.h"

uintptr_t serialize(Data* ptr) { return reinterpret_cast<uintptr_t>(ptr); }

Data* deserialize(uintptr_t raw) { return reinterpret_cast<Data*>(raw); }

Data::Data(int i, char c) : i(i), c(c) {}

int main(void) {
  Data d(1, 'c');

  uintptr_t d_ser = serialize(&d);
  std::cout << d_ser << std::endl;
  Data* d_ptr = deserialize(d_ser);
  std::cout << d_ptr << std::endl;
  std::cout << "i: " << d_ptr->i << std::endl;
  std::cout << "c: " << d_ptr->c << std::endl;
}
