#include "Rectangle.hpp"

Rectangle::Rectangle(Vector2D<int> const& size, Vector2D<int> const& coord) : size(size), coord(coord) {
}

Vector2D<int> const& Rectangle::getSize() const {
  return size;
}

Vector2D<int> const& Rectangle::getCoord() const {
  return coord;
}

int const& Rectangle::getH() const {
  return size.getY();
}

int const& Rectangle::getW() const {
  return size.getX();
}

int const& Rectangle::getX() const {
  return coord.getX();
}

int const& Rectangle::getY() const {
  return coord.getY();
}

void Rectangle::setCoord(Vector2D<int> const& coord) {
  this->coord = coord;
}

void Rectangle::setSize(Vector2D<int> const& size) {
  this->size = size;
}

SDL_Rect Rectangle::getRect() const {
  SDL_Rect rect;
  rect.x = getX();
  rect.y = getY();
  rect.w = getW();
  rect.h = getH();
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
  return !(p.getX() < coord.getX() || p.getX() > coord.getX() + size.getX() || p.getY() > coord.getY() + size.getY() || p.getY() < coord.getY() );
}
