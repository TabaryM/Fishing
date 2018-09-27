#include "Object.hpp"

Object::Object(Renderer const& r, Surface* s, int const& x, int const& y) : graphic(r, s, x, y) {
  //return imBoat;
}

Object::~Object(){
}

Texture& Object::getTexture(){
  return graphic;
}
