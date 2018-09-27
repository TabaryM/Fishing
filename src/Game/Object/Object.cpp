#include "Object.hpp"

Object::Object(Renderer const& r, Surface* s, int const& x, int const& y) : graphic(r, s, x, y) {
  //return imBoat;
}

Object::~Object(){
}

Texture& Object::getTexture(){
  return graphic;
}

void Object::setX(int const& x){
  graphic.setX(x);
}

void Object::setY(int const& y){
  graphic.setX(y);
}
