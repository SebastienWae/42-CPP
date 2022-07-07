#include "Point.h"
#include "Fixed.h"

Point::Point(void) : x(0), y(0) {}

Point::Point(Fixed x, Fixed y) : x(x), y(y) {}

Point::Point(const Point& p) : x(p.x), y(p.y) {}

Fixed const& Point::getX(void) const {
  return x;
}
Fixed const& Point::getY(void) const {
  return y;
}

Point::~Point() {}

// https://stackoverflow.com/questions/4136156/const-member-and-assignment-operator-how-to-avoid-the-undefined-behavior
Point& Point::operator=(const Point& p) {
  (void)p;
  return *this;
}

bool Point::operator==(Point const& other) const {
  return x == other.getX() && y == other.getY();
}

std::ostream& operator<<(std::ostream& os, Point const& point) {
  os << "Point(" << point.getX() << ", " << point.getY() << ")";
  return os;
}
