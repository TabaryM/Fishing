#include "GoldFish.hpp"

GoldFish::GoldFish(Renderer const& r, Vector2D<int> coord, float const& z) : Fish(r, coord, z, 2) {
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

void GoldFish::setDegre(float d){
  setDegre(d);
}

float GoldFish::getDegre(){
  return getDegre();
}
