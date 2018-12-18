#include "Object.hpp"

Object::Object(Renderer const& r, Surface* s, Vector2D<int> const& coord, float const& z, bool destroyOnload, bool active) : graphic(r, s, coord, destroyOnload), z(z), flip(false), active(active), dependant(false) {
}

Object::~Object(){
}

void Object::link(Object* c){
  child.push_back(c);
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
  return getCoord().getX();
}

int const& Object::getY() const {
  return getCoord().getY();
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
  if(getType()==FISH && !isDependant()){
    flip = dep.getX() < 0;
  }
  graphic.setCoord(graphic.getCoord() + dep);
  for (Object* o : child) {
    o->move(dep);
  }
}

void Object::collide(std::function<void(Object*, Object*)> callback, Object* o){
  bool col = false;
  Vector2D<int>* corner = getCorner();

  for (int i = 0; i < 4; i++) {
    col = col || o->getHitbox().pointIn(corner[i]);
  }
  delete[] corner;
  corner = nullptr;

  if (col) {
    callback(this, o);
  }
}

Vector2D<int>* Object::getCorner() {
  return graphic.getPosition().getCorner();
}

Rectangle Object::getHitbox() {
  return graphic.getPosition();
}

int Object::getType() {
  return OBJECT;
}

std::vector<Object*>& Object::getChild(){
  return child;
}

void Object::flipingTo(bool a){
  flip = a;
}

bool const& Object::isFliped() const{
  return flip ;
}


void Object::updateTexture(Renderer const& r, Surface* s) {
  graphic.update(r, s);
}

void Object::isFlip(){
  flip = !flip;
}

void Object::setActive(bool a) {
  active = a;
  for (Object* o : child) {
    o->setActive(a);
  }
}

bool Object::isActive(){
  return active;

}

void Object::depend(){
  dependant = !dependant;
}

bool Object::isDependant(){
  return dependant;

}
