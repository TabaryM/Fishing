#include "Fish.hpp"

Fish::Fish(Renderer const& r, Vector2D<int> const& coord, float const& z) : Object(r, new Surface("sprites/fish/Jebaifish.png"), coord, z), direction(0.0) {
  this->direction = rand() % 10 - 5;
  this->hooked = false;
}

Fish::~Fish(){
}

float Fish::getDir(){
  return this->direction;
}

void Fish::setDir(float d){
  this->direction = d;
}

void Fish::setHook(){
  this->hooked = true;
}

int Fish::getType() {
  return FISH;
}

bool const& Fish::isHooked() const{
  return hooked;
}
