#include "Point.h"

#include "Fixed.h"

Point::Point() : x(0), y(0) {}

Point::Point(float const& x, float const& y) : x(Fixed(x)), y(Fixed(y)) {}

Point::Point(Fixed const& x, Fixed const& y) : x(x), y(y) {}

Point::Point(Point const& other) : x(other.x), y(other.y) {}

Fixed const& Point::getX(void) const { return x; }

Fixed const& Point::getY(void) const { return y; }

Point::~Point() {}

// https://stackoverflow.com/questions/4136156/const-member-and-assignment-operator-how-to-avoid-the-undefined-behavior
Point& Point::operator=(const Point& other) {
  (void)other;
  return *this;
}

bool Point::operator==(Point const& other) const { return x == other.x && y == other.y; }

std::ostream& operator<<(std::ostream& os, Point const& point) {
  os << "Point(" << point.getX() << ", " << point.getY() << ")";
  return os;
}
