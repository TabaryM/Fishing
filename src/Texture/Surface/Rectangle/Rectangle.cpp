#include "Rectangle.hpp"

Rectangle::Rectangle() : Rectangle(0, 0, 0, 0) {

}

Rectangle::Rectangle(int const& w, int const& h, int const& x, int const& y){
  item.x = x; item.y = y;
  item.w = w; item.h = h;
}

Rectangle::~Rectangle(){

}

void Rectangle::setX(int const& x){
  item.x = x;
}

void Rectangle::setY(int const& y){
  item.y = y;
}

int const& Rectangle::getX() const {
  return item.x;
}

int const& Rectangle::getY() const {
  return item.y;
}

int const& Rectangle::getW() const {
  return item.w;
}

int const& Rectangle::getH() const {
  return item.h;
}

SDL_Rect const& Rectangle::getItem() const {
  return item;
}
