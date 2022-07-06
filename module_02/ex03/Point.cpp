#include "Point.h"
#include "Fixed.h"

Point::Point(void) : x(0), y(0) {}

Point::Point(Fixed x, Fixed y) : x(x), y(y) {}

Point::Point(const Point& p) {
  x = p.x;
  y = p.y;
}

Point& Point::operator=(const Point& p) {
  p.x = x;
  p.y = y;
  return *this;
}

Point::~Point() {}
