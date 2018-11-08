#include "Object.hpp"

Object::Object(String name,Renderer const& r, Surface* s, Vector2D<int> const& coord, float const& z) : graphic(r, s, coord), z(z) {
}

Object::~Object(){
}

void Object::link(Object* c){
  child.push_back(c);
  c->setZ(z + static_cast <float> (child.size()) / getDepth());
}

Texture& Object::getTexture(){
  return graphic;
}

void Object::setZ(float const& v) {
  z = v;
}

Vector2D<int> const& Object::getCoord() const {
  return graphic.getPosition().getCoord();
}

int const& Object::getX() const {
  return graphic.getCoord().getX();
}

int const& Object::getY() const {
  return graphic.getCoord().getY();
}

Vector2D<int> const& Object::getSize() const {
  return graphic.getPosition().getSize();
}

int const& Object::getW() const {
  return graphic.getPosition().getSize().getX();
}

int const& Object::getH() const {
  return graphic.getPosition().getSize().getY();
}

float const& Object::getZ() const {
  return z;
}

float Object::getDepth() const {
  if (child.size() == 0) {
    return 1.0;
  }
  return 10.0 * child[0]->getDepth();
}

void Object::move(Vector2D<int> const& dep) {
  graphic.setCoord(graphic.getCoord() + dep);
  for (Object* o : child) {
    o->move(dep);
  }
}

void Object::collide(std::function<void(Object*, Object*)> callback, Object* o){

  bool col = false;
  Vector2D<int>* corner = graphic.getPosition().getCorner();

  for (int i = 0; i < 4; i++) {
    col = col || o->graphic.getPosition().pointIn(corner[i]);
  }
  delete[] corner;


  if (col) {
    callback(this, o);
  }
}

int Object::getType() {
  return OBJECT;
}

std::vector<Object*>& Object::getChild(){
  return child;
}
