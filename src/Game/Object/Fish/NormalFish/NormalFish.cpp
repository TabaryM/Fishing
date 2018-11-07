#include "NormalFish.hpp"

NormalFish::NormalFish(Renderer const& r, std::string s, Vector2D<int> coord, float const& z) : Fish(r, "sprites/fish/Normalfish.png" , coord, z) {
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
