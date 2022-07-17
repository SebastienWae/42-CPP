#ifndef POINT_H
#define POINT_H

#include "Fixed.h"

class Point {
  const Fixed x;
  const Fixed y;

public:
  Point();
  Point(float const& x, float const& y);
  Point(Fixed const& x, Fixed const& y);
  Point(Point const& other);

  Fixed const& getX(void) const;
  Fixed const& getY(void) const;

  Point& operator=(Point const& other);

  bool operator==(Point const& other) const;

  ~Point();
};

std::ostream& operator<<(std::ostream& os, Point const& point);

#endif
