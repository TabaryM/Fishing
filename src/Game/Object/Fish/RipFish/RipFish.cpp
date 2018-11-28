#include "RipFish.hpp"

RipFish::RipFish(Renderer const& r, Vector2D<int> coord, float const& z) : Fish(r, coord, z, 4) {
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

void RipFish::setDegre(float d){
  setDegre(d);
}

float RipFish::getDegre(){
  return getDegre();
}