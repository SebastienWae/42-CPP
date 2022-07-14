#ifndef ITER_H
#define ITER_H

#include <cstddef>

template <class T> void iter(T* addr, std::size_t len, void (*func)(T const&)) {
  for (size_t i = 0; i < len; ++i) {
    func(addr[i]);
  }
}

#endif
