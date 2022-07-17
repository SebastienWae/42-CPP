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

  Fixed const ab_ap = Fixed((ab.getX() * ap.getY()) - (ap.getX() * ab.getY()));
  Fixed const bc_bp = Fixed((bc.getX() * bp.getY()) - (bp.getX() * bc.getY()));
  Fixed const ca_cp = Fixed((ca.getX() * cp.getY()) - (cp.getX() * ca.getY()));

  return (ab_ap < 0 && bc_bp < 0 && ca_cp < 0) || (ab_ap > 0 && bc_bp > 0 && ca_cp > 0);
}
