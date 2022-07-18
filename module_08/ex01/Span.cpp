#include "Span.h"

#include <algorithm>
#include <iterator>
#include <numeric>

char const* Span::EmptySpan::what() const throw() { return "Span is empty"; }

char const* Span::FullSpan::what() const throw() { return "Span is full"; }

Span::Span() : capacity(0) {}

Span::Span(unsigned int n) : capacity(n) {}

Span::Span(Span const& other) : capacity(other.capacity), vec(other.vec) {}

Span::~Span() {}

Span& Span::operator=(Span const& other) {
  capacity = other.capacity;
  vec = other.vec;
  return *this;
}

void Span::addNumber(int n) throw(FullSpan) {
  if (vec.size() == capacity) {
    throw FullSpan();
  }
  std::vector<int>::iterator it = std::upper_bound(vec.begin(), vec.end(), n);
  vec.insert(it, n);
}

void Span::addNumberRange(std::vector<int>::iterator begin,
                          std::vector<int>::iterator end) throw(FullSpan) {
  for (; begin != end; ++begin) {
    addNumber(*begin);
  }
}

std::size_t Span::shortestSpan() const throw(EmptySpan) {
  if (vec.size() <= 1) {
    throw EmptySpan();
  }

  std::vector<int> tmp_vec(vec.size(), 0);
  std::adjacent_difference(vec.begin(), vec.end(), tmp_vec.begin());

  std::vector<int>::iterator iter;
  for (iter = tmp_vec.begin(); iter != tmp_vec.end(); ++iter) {
    *iter = std::abs(*iter);
  }

  return (*std::min_element(tmp_vec.begin() + 1, tmp_vec.end()));
}

std::size_t Span::longestSpan() const throw(EmptySpan) {
  if (vec.size() <= 1) {
    throw EmptySpan();
  }

  int max = *std::max_element(vec.begin(), vec.end());
  int min = *std::min_element(vec.begin(), vec.end());

  return std::abs(max - min);
}
