#include "Fixed.h"
#include "Point.h"

bool Bsp(Point const a, Point const b, Point const c, Point const point) {
  if (point == a || point == b || point == c) {
    return false;
  }

  Point const ab(b.GetX() - a.GetX(), b.GetY() - a.GetY());
  Point const bc(c.GetX() - b.GetX(), c.GetY() - b.GetY());
  Point const ca(a.GetX() - c.GetX(), a.GetY() - c.GetY());

  Point const ap(point.GetX() - a.GetX(), point.GetY() - a.GetY());
  Point const bp(point.GetX() - b.GetX(), point.GetY() - b.GetY());
  Point const cp(point.GetX() - c.GetX(), point.GetY() - c.GetY());

  Fixed const ab_ap = Fixed((ab.GetX() * ap.GetY()) - (ap.GetX() * ab.GetY()));
  Fixed const bc_bp = Fixed((bc.GetX() * bp.GetY()) - (bp.GetX() * bc.GetY()));
  Fixed const ca_cp = Fixed((ca.GetX() * cp.GetY()) - (cp.GetX() * ca.GetY()));

  return (ab_ap < 0 && bc_bp < 0 && ca_cp < 0) || (ab_ap > 0 && bc_bp > 0 && ca_cp > 0);
}
