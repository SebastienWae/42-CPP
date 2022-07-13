#include "convert.h"

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

int main(int argc, char **argv) {
  if (argc == 2) {
    std::string input = argv[1];
    enum type detected_type;
    if (!input.empty()) {
      detected_type = detectType(input);
    } else {
      detected_type = UNKNOWN;
    }
    switch (detected_type) {
      case UNKNOWN:
        std::cout << "Unknown input" << std::endl;
        break;
      case CHAR:
        convert(input.at(0));
        break;
      case INT:
        convert(atoi(input.c_str()));
        break;
      case FLOAT:
        convert(static_cast<float>(std::strtod(input.c_str(), NULL)));
        break;
      case DOUBLE:
        convert(std::strtod(input.c_str(), NULL));
        break;
      case NAN_FLOAT:
        convert(std::numeric_limits<float>::quiet_NaN());
        break;
      case INF_FLOAT:
        convert(std::numeric_limits<float>::infinity());
        break;
      case N_INF_FLOAT:
        convert(-std::numeric_limits<float>::infinity());
        break;
      case NAN_DOUBLE:
        convert(std::numeric_limits<double>::quiet_NaN());
        break;
      case INF_DOUBLE:
        convert(std::numeric_limits<double>::infinity());
        break;
      case N_INF_DOUBLE:
        convert(-std::numeric_limits<double>::infinity());
        break;
    }
  }
}

enum type detectType(std::string &input) {
  if (input == "-inff") {
    return N_INF_FLOAT;
  }
  if (input == "+inff") {
    return INF_FLOAT;
  }
  if (input == "nanf") {
    return NAN_FLOAT;
  }
  if (input == "-inf") {
    return N_INF_DOUBLE;
  }
  if (input == "+inf") {
    return INF_DOUBLE;
  }
  if (input == "nan") {
    return NAN_DOUBLE;
  }

  unsigned long i;
  bool is_negative = false;
  long n = 0;
  for (i = 0; input[i] != 0; ++i) {
    if (input[i] == '-') {
      if (i == 0) {
        is_negative = true;
        continue;
      }
      i = 0;
      break;
    }
    if (std::isdigit(input[i]) == 0) {
      i = 0;
      break;
    }
    n *= 10;
    n += input[i] - '0';
    if (is_negative) {
      if (n - 1 > std::numeric_limits<int>::max()) {
        i = 0;
        break;
      }
    } else {
      if (n > std::numeric_limits<int>::max()) {
        i = 0;
        break;
      }
    }
  }
  if (i == input.length()) {
    return INT;
  }

  char *out;
  double d = std::strtod(input.c_str(), &out);
  if (input != out && d != HUGE_VAL) {
    if (input.at(input.length() - 1) == 'f') {
      if (d <= std::numeric_limits<float>::max() && d >= -std::numeric_limits<float>::max()) {
        return FLOAT;
      }
    } else {
      return DOUBLE;
    }
  }

  if (input.length() == 1 && input.at(0) >= 32 && input.at(0) <= 126) {
    return CHAR;
  }
  return UNKNOWN;
}

void convert(char c) {
  std::cout << "char: " << c << std::endl;

  int i = static_cast<int>(c);
  std::cout << "int: " << i << std::endl;

  float f = static_cast<float>(c);
  std::cout << "float: " << f << std::endl;

  double d = static_cast<double>(c);
  std::cout << "double: " << d << std::endl;
}

void convert(int i) {
  if (i >= 32 && i <= 126) {
    char c = static_cast<char>(i);
    std::cout << "char: " << c << std::endl;
  } else if (i > std::numeric_limits<char>::max() || i < std::numeric_limits<char>::min()) {
    std::cout << "char: Overlfow" << std::endl;
  } else {
    std::cout << "char: Non displayable" << std::endl;
  }

  std::cout << "int: " << i << std::endl;

  float f = static_cast<float>(i);
  std::cout << "float: " << f << std::endl;

  double d = static_cast<double>(i);
  std::cout << "double: " << d << std::endl;
}

void convert(float f) {
  float intpart;
  float dec = modf(f, &intpart);

  if (dec == 0 && intpart >= 32 && intpart <= 126) {
    char c = static_cast<char>(intpart);
    std::cout << "char: " << c << std::endl;
  } else if (intpart > std::numeric_limits<char>::max()
             || intpart < std::numeric_limits<char>::min()) {
    std::cout << "char: Overlfow" << std::endl;
  } else {
    std::cout << "char: Non displayable" << std::endl;
  }

  if (intpart > std::numeric_limits<int>::max()
      || (dec > 0. && intpart == std::numeric_limits<int>::max())
      || intpart < std::numeric_limits<int>::min()
      || (dec < 0. && intpart == std::numeric_limits<int>::min())) {
    std::cout << "int: Overlfow" << std::endl;
  } else {
    int i = static_cast<int>(intpart);
    std::cout << "int: " << i << std::endl;
  }

  std::cout << "float: " << f << std::endl;

  double d = static_cast<double>(f);
  std::cout << "double: " << d << std::endl;
}

void convert(double d) {
  double intpart;
  double dec = modf(d, &intpart);

  if (dec == 0 && intpart >= 32 && intpart <= 126) {
    char c = static_cast<char>(intpart);
    std::cout << "char: " << c << std::endl;
  } else if (intpart > std::numeric_limits<char>::max()
             || intpart < std::numeric_limits<char>::min()) {
    std::cout << "char: Overlfow" << std::endl;
  } else {
    std::cout << "char: Non displayable" << std::endl;
  }

  if (intpart > std::numeric_limits<int>::max()
      || (dec > 0. && intpart == std::numeric_limits<int>::max())
      || intpart < std::numeric_limits<int>::min()
      || (dec < 0. && intpart == std::numeric_limits<int>::min())) {
    std::cout << "int: Overlfow" << std::endl;
  } else {
    int i = static_cast<int>(intpart);
    std::cout << "int: " << i << std::endl;
  }

  if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max()) {
    std::cout << "float: Overlfow" << std::endl;
  } else {
    float f = static_cast<float>(d);
    std::cout << "float: " << f << std::endl;
  }

  std::cout << "double: " << d << std::endl;
}
