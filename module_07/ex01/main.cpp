#include <iostream>

#include "iter.h"

template <typename T> void print(T x) { std::cout << x << std::endl; }

int main() {
  {
    int arr[] = {0, 1, 2, 3, 4};
    iter(arr, sizeof(arr) / sizeof(arr[0]), print);
  }
  {
    std::string str = "hello";
    iter(str.c_str(), str.length(), print);
  }
}