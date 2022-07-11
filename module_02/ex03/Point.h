// ◦ A default constructor that initializes x and y to 0.
// ◦ A constructor that takes as parameters two constant floating-point numbers.
// It initializes x and y with those parameters.
// ◦ A copy constructor.
// ◦ A copy assignment operator overload.
// ◦ A destructor.
// ◦ Anything else usefu

#ifndef POINT_H
#define POINT_H

#include "Fixed.h"

class Point {
  const Fixed x_;
  const Fixed y_;

public:
  Point();
  Point(Fixed x, Fixed y);
  Point(const Point& p);

  Fixed const& GetX(void) const;
  Fixed const& GetY(void) const;

  Point& operator=(Point const& p);
  bool operator==(Point const& other) const;

  ~Point();
};

std::ostream& operator<<(std::ostream& os, Point const& point);

bool Bsp(Point const a, Point const b, Point const c, Point const point);

#endif
