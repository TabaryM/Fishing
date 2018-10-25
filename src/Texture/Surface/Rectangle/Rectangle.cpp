#include "Rectangle.hpp"

Rectangle::Rectangle(Vector2D<int> const& size, Vector2D<int> const& coord) : size(size), coord(coord) {
}

Vector2D<int> const& Rectangle::getCoord() const {
  return coord;
}

Vector2D<int> const& Rectangle::getSize() const {
  return size;
}

int const& Rectangle::getH() const {
  return size.getY();
}

int const& Rectangle::getW() const {
  return size.getX();
}

void Rectangle::setCoord(Vector2D<int> const& coord) {
  this->coord = coord;
}

SDL_Rect Rectangle::getRect() const {
  SDL_Rect rect;
  rect.x = coord.getX();
  rect.y = coord.getY();
  rect.w = size.getX();
  rect.h = size.getY();
  return rect;
}

Vector2D<int>* Rectangle::getCorner() const {
  Vector2D<int>* c = new Vector2D<int>[4];
  Vector2D<int> hd(getCoord() + getSize());
  Vector2D<int> bg(getCoord());
  Vector2D<int> hg(hd);
  hg.setX(bg.getX());
  Vector2D<int> bd(bg);
  bd.setX(hd.getX());
  c[0] = hg;
  c[1] = hd;
  c[2] = bg;
  c[3] = bd;
  return c;
}

bool Rectangle::pointIn(Vector2D<int> const& p) const {
  return !(p.getX() < coord.getX() || p.getX() > coord.getX() + size.getX() || p.getY() > coord.getY() || p.getY() < coord.getY());
}
