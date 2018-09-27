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


SDL_Rect const& Rectangle::getItem() const {
  return item;
}
