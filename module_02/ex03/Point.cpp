#include "Point.h"

#include "Fixed.h"

Point::Point() : x_(0), y_(0) {}

Point::Point(Fixed x, Fixed y) : x_(x), y_(y) {}

Point::Point(const Point& p) : x_(p.x_), y_(p.y_) {}

Fixed const& Point::GetX(void) const { return x_; }
Fixed const& Point::GetY(void) const { return y_; }

Point::~Point() {}

// https://stackoverflow.com/questions/4136156/const-member-and-assignment-operator-how-to-avoid-the-undefined-behavior
Point& Point::operator=(const Point& p) {
  (void)p;
  return *this;
}

bool Point::operator==(Point const& other) const {
  return x_ == other.GetX() && y_ == other.GetY();
}

std::ostream& operator<<(std::ostream& os, Point const& point) {
  os << "Point(" << point.GetX() << ", " << point.GetY() << ")";
  return os;
}
