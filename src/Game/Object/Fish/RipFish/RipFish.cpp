#include "RipFish.hpp"

RipFish::RipFish(Renderer const& r, int const& x, int const& y, float const& z) : Fish(r, "sprites/fish/Ripfish.png" , x, y, z) {
  this->valeur = 2;
}

RipFish::~RipFish(){
}

float RipFish::getDir(){
  return getDir();
}

void RipFish::setDir(float d){
  setDir(d);
}

int RipFish::getValue(){
  return this->valeur;
}