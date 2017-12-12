#include "ship.h"
#include "gfxnew.h"

int Ship::moveLeft(int x)
{
  if (x < 15) {
    return 15;
  }
  else
    return x - 5;
}

int Ship::moveRight(int x)
{
  if (x > 495)
    return 495;
  else
    return x + 5;
}

void Ship::createShip(int x, int y, int rad)
{
  gfx_line(x - rad, y, x + rad, y);
  gfx_line(x + rad, y, x, y - rad);
  gfx_line(x, y - rad, x - rad, y);
}
