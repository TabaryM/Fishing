#include "Object.hpp"

Object::Object(Renderer const& r, Surface* s, int const& x, int const& y, float const& z) : graphic(r, s, x, y), z(z) {
}

Object::~Object(){
}

void Object::link(Object* c){
  child.push_back(c);
  c->setZ(z - static_cast <float> (child.size()) / getDepth());
}

Texture& Object::getTexture(){
  return graphic;
}

void Object::setZ(float const& v) {
  z = v;
}

int const& Object::getX() const{
  return graphic.getPosition().getX();
}

int const& Object::getY() const{
  return graphic.getPosition().getY();
}

float const& Object::getZ() const {
  return z;
}

int const& Object::getW() const{
  return graphic.getPosition().getW();
}

int const& Object::getH() const{
  return graphic.getPosition().getH();
}

float Object::getDepth() const {
  if (child.size() == 0) {
    return 1.0;
  }
  return 10.0 * child[0]->getDepth();
}

void Object::move(float const& x, float const& y) {
  graphic.setX(getX() + x);
  graphic.setY(getY() + y);
  for (Object* o : child) {
    o->move(x, y);
  }
}

void Object::borderCollide(Rectangle const& r){

  if(getX() < r.getX() && getX()+getW() < r.getX() + r.getW()){
    
  }
}
