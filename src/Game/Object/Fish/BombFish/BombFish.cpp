#include "BombFish.hpp"

BombFish::BombFish(Renderer const& r, int const& x, int const& y, float const& z) : Fish(r, "sprites/fish/Bombfish.png" , x, y, z) {
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