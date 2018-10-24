#include "GoldFish.hpp"

GoldFish::GoldFish(Renderer const& r, int const& x, int const& y, float const& z) : Fish(r, "sprites/fish/Goldfish.png" , x, y, z) {
  this->valeur = 10;
}

GoldFish::~GoldFish(){
}

float GoldFish::getDir(){
  return getDir();
}

void GoldFish::setDir(float d){
  setDir(d);
}

int GoldFish::getValue(){
  return this->valeur;
}