#include "FastFish.hpp"

FastFish::FastFish(Renderer const& r, int const& x, int const& y, float const& z) : Fish(r, "sprites/fish/Fastfish.png" , x, y, z) {
  this->valeur = 2;
}

FastFish::~FastFish(){
}

float FastFish::getDir(){
  return getDir();
}

void FastFish::setDir(float d){
  setDir(d);
}

int FastFish::getValue(){
  return this->valeur;
}

void FastFish::setDegre(float d){
  setDegre(d);
}

float FastFish::getDegre(){
  return getDegre();
}