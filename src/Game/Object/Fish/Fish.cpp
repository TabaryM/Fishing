#include "Fish.hpp"

Fish::Fish(Renderer const& r, int const& x, int const& y, float const& z) : Object(r, new Surface("sprites/fish/Jebaifish.png"), x, y, z), direction(0.0) {
  this->direction = rand() % 10 - 5;
}

Fish::~Fish(){
}

float Fish::getDir(){
  return this->direction;
}

void Fish::setDir(float d){
  this->direction = d;
}
