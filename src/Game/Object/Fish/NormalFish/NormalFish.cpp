#include "NormalFish.hpp"

NormalFish::NormalFish(Renderer const& r, int const& x, int const& y, float const& z) : Fish(r, "sprites/fish/Normalfish.png" , x, y, z) {
  this->valeur = 1;
}

NormalFish::~NormalFish(){
}

float NormalFish::getDir(){
  return getDir();
}

void NormalFish::setDir(float d){
  setDir(d);
}

int NormalFish::getValue(){
  return this->valeur;
}

void NormalFish::setDegre(float d){
  setDegre(d);
}

float NormalFish::getDegre(){
  return getDegre();
}