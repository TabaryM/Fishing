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
