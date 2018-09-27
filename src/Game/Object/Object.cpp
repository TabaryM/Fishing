#include "Object.hpp"

Object::Object(Renderer const& r, Surface* s, int const& x, int const& y, int const& z) : graphic(r, s, x, y), z(z) {
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
  graphic.setY(y);
}

int const& Object::getX() const{
  return graphic.getPosition().getX();
}

int const& Object::getY() const{
  return graphic.getPosition().getY();
}

int const& Object::getZ() const {
  return z;
}

int const& Object::getW() const{
  return graphic.getPosition().getW();
}

int const& Object::getH() const{
  return graphic.getPosition().getH();
}
