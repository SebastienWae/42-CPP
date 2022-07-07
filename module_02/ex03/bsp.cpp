#include "Fixed.h"
#include "Point.h"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  if (point == a || point == b || point == c) {
    return false;
  }

  Point const ab(b.getX() - a.getX(), b.getY() - a.getY());
  Point const bc(c.getX() - b.getX(), c.getY() - b.getY());
  Point const ca(a.getX() - c.getX(), a.getY() - c.getY());

  Point const ap(point.getX() - a.getX(), point.getY() - a.getY());
  Point const bp(point.getX() - b.getX(), point.getY() - b.getY());
  Point const cp(point.getX() - c.getX(), point.getY() - c.getY());

  Fixed const abXap = Fixed((ab.getX() * ap.getY()) - (ap.getX() * ab.getY()));
  Fixed const bcXbp = Fixed((bc.getX() * bp.getY()) - (bp.getX() * bc.getY()));
  Fixed const caXcp = Fixed((ca.getX() * cp.getY()) - (cp.getX() * ca.getY()));

  return (abXap < 0 && bcXbp < 0 && caXcp < 0) ||
         (abXap > 0 && bcXbp > 0 && caXcp > 0);
}
