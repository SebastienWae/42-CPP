#include <algorithm>
#include <iostream>
#include <limits>

#include "Span.h"

int main() {
  srand(time(NULL));
  {
    std::cout << "### TEST 1 ###" << std::endl;

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }
  {
    std::cout << "### TEST 2 ###" << std::endl;

    Span empty;
    try {
      empty.addNumber(42);
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }

    Span two(2);
    try {
      two.addNumber(42);
      two.addNumber(0);
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
    try {
      std::cout << two.shortestSpan() << std::endl;
      std::cout << two.longestSpan() << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
    std::vector<int> vec(10);
    try {
      two.addNumberRange(vec.begin(), vec.end());
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    std::cout << "### TEST 3 ###" << std::endl;

    Span two(2);
    two.addNumber(42);
    two.addNumber(42);
    std::cout << two.shortestSpan() << std::endl;
    std::cout << two.longestSpan() << std::endl;
  }
  {
    std::cout << "### TEST 4 ###" << std::endl;

    Span two(2);
    two.addNumber(21);
    two.addNumber(-21);

    std::cout << two.shortestSpan() << std::endl;
    std::cout << two.longestSpan() << std::endl;
  }
  {
    std::cout << "### TEST 5 ###" << std::endl;

    Span two(2);
    two.addNumber(std::numeric_limits<int>::min());
    two.addNumber(std::numeric_limits<int>::max());

    std::cout << two.shortestSpan() << std::endl;
    std::cout << two.longestSpan() << std::endl;
    std::cout << std::numeric_limits<unsigned int>::max() << " <- unsigned int max" << std::endl;
  }
  {
    std::cout << "### TEST 6 ###" << std::endl;
    std::vector<int> vec(10000);
    std::generate(vec.begin(), vec.end(), rand);

    Span large(10000);
    large.addNumberRange(vec.begin(), vec.end());
    std::cout << large.shortestSpan() << std::endl;
    std::cout << large.longestSpan() << std::endl;
  }
  {
    std::cout << "### TEST 7 ###" << std::endl;
    unsigned int const N = 100000;
    std::cout << "Test with " << N << " random numbers:" << std::endl;
    std::vector<int> vec(N);
    std::generate(vec.begin(), vec.end(), rand);
    vec[0] *= -1;

    Span large(N);
    large.addNumberRange(vec.begin(), vec.end());
    std::cout << large.shortestSpan() << std::endl;
    std::cout << large.longestSpan() << std::endl;
  }
}
