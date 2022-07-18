#ifndef SPAN_H
#define SPAN_H

#include <cstddef>
#include <exception>
#include <vector>

class Span {
  unsigned int capacity;
  std::vector<int> vec;

public:
  Span();
  Span(unsigned int n);
  Span(Span const& other);

  ~Span();

  Span& operator=(Span const& other);

  class EmptySpan : public std::exception {
  public:
    virtual char const* what() const throw();
  };

  class FullSpan : public std::exception {
  public:
    virtual char const* what() const throw();
  };

  void addNumber(int n) throw(FullSpan);
  void addNumberRange(std::vector<int>::iterator begin,
                      std::vector<int>::iterator end) throw(FullSpan);

  std::size_t shortestSpan() const throw(EmptySpan);
  std::size_t longestSpan() const throw(EmptySpan);
};

#endif
