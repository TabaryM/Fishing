#include "BombFish.hpp"

BombFish::BombFish(Renderer const& r,  Vector2D<int> coord, float const& z) : Fish(r, coord, z, 5) {
  this->valeur = 2;
}

BombFish::~BombFish(){
}

float BombFish::getDir(){
  return getDir();
}

void BombFish::setDir(float d){
  setDir(d);
}

int BombFish::getValue(){
  return this->valeur;
}

void BombFish::setDegre(float d){
  setDegre(d);
}

float BombFish::getDegre(){
  return getDegre();
}
