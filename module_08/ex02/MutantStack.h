#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <stack>

template <typename T, typename Container = std::deque<T> > class MutantStack
    : public std::stack<T, Container> {
public:
  MutantStack() : std::stack<T, Container>() {}

  MutantStack<T, Container>(MutantStack<T, Container> const& other) : std::stack<T>::c(other.c) {}

  MutantStack<T, Container>& operator=(MutantStack<T, Container> const& other) {
    if (this == &other) {
      return *this;
    }

    std::stack<T>::c = other.c;
    return *this;
  }

  ~MutantStack() {}

  typedef typename Container::iterator iterator;
  typedef typename Container::const_iterator const_iterator;
  typedef typename Container::reverse_iterator reverse_iterator;
  typedef typename Container::const_reverse_iterator const_reverse_iterator;

  iterator begin() { return std::stack<T>::c.begin(); }
  iterator end() { return std::stack<T>::c.end(); }
  const_iterator begin() const { return std::stack<T>::c.begin(); }
  const_iterator end() const { return std::stack<T>::c.end(); }
  reverse_iterator rbegin() { return std::stack<T>::c.rbegin(); }
  reverse_iterator rend() { return std::stack<T>::c.rend(); }
  const_reverse_iterator rbegin() const { return std::stack<T>::c.rbegin(); }
  const_reverse_iterator rend() const { return std::stack<T>::c.rend(); }
};

#endif