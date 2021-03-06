#include <algorithm>
#include <iostream>
#include <limits>

#include "Span.h"

int main() {
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

    // fix
    Span one(1);
    try {
      one.addNumber(42);
      one.addNumber(0);
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
    try {
      std::cout << one.longestSpan() << std::endl;
      std::cout << one.shortestSpan() << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
    std::vector<int> vec(10);
    try {
      one.addNumberRange(vec.begin(), vec.end());
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    std::cout << "### TEST 3 ###" << std::endl;

    Span two(2);
    two.addNumber(42);
    two.addNumber(42);
    std::cout << two.longestSpan() << std::endl;
    std::cout << two.shortestSpan() << std::endl;
  }
  {
    std::cout << "### TEST 4 ###" << std::endl;

    Span two(2);
    two.addNumber(21);
    two.addNumber(-21);

    std::cout << two.longestSpan() << std::endl;
    std::cout << two.shortestSpan() << std::endl;
  }
  {
    std::cout << "### TEST 5 ###" << std::endl;

    // fix
    Span two(2);
    two.addNumber(std::numeric_limits<int>::max());
    two.addNumber(std::numeric_limits<int>::min());

    std::cout << two.longestSpan() << std::endl;
    std::cout << two.shortestSpan() << std::endl;
    std::cout << std::numeric_limits<unsigned int>::max() << " <- unsigned int max" << std::endl;
  }
  {
    std::cout << "### TEST 6 ###" << std::endl;
    std::vector<int> vec(10000);
    std::generate(vec.begin(), vec.end(), rand);

    Span large(10000);
    large.addNumberRange(vec.begin(), vec.end());
    std::cout << large.longestSpan() << std::endl;
    std::cout << large.shortestSpan() << std::endl;
  }
  {
    std::cout << "### TEST 7 ###" << std::endl;
    unsigned int const N = 200000;
    std::cout << "Test with " << N << " random numbers:" << std::endl;
    std::vector<int> vec(N);
    std::generate(vec.begin(), vec.end(), rand);
    vec[0] *= -1;

    Span large(N);
    large.addNumberRange(vec.begin(), vec.end());
    std::cout << large.longestSpan() << std::endl;
    std::cout << large.shortestSpan() << std::endl;
  }
}
