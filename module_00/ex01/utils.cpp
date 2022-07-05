#include "utils.h"

#include <cstddef>
#include <string>

std::string Truncate(const std::string& str, size_t width) {
  if (str.length() > width) {
    return str.substr(0, width - 1) + ".";
  }
  return str;
}
