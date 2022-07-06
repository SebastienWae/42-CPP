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
  const Fixed x;
  const Fixed y;

 public:
  Point(void);
  Point(Fixed x, Fixed y);
  Point(const Point& p);

  Point& operator=(const Point& p);

  ~Point();
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
