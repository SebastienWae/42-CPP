#include "Span.h"

#include <algorithm>
#include <iterator>
#include <limits>
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

  unsigned int shortest = std::numeric_limits<unsigned int>::max();
  for (std::vector<int>::const_iterator it = vec.begin(); it + 1 != vec.end(); ++it) {
    unsigned int dif = std::abs(static_cast<long>(*it) - static_cast<long>(*(it + 1)));
    if (dif < shortest) {
      shortest = dif;
    }
  }
  return shortest;
}

std::size_t Span::longestSpan() const throw(EmptySpan) {
  if (vec.size() <= 1) {
    throw EmptySpan();
  }

  int max = *std::max_element(vec.begin(), vec.end());
  int min = *std::min_element(vec.begin(), vec.end());

  return std::abs(max - min);
}
