#ifndef CONVERT_H
#define CONVERT_H

#include <string>

enum type {
  UNKNOWN,
  CHAR,
  INT,
  FLOAT,
  DOUBLE,
  NAN_FLOAT,
  INF_FLOAT,
  N_INF_FLOAT,
  NAN_DOUBLE,
  INF_DOUBLE,
  N_INF_DOUBLE
};

type detectType(std::string &input);

void convert(char c);
void convert(int i);
void convert(float f);
void convert(double d);

#endif
