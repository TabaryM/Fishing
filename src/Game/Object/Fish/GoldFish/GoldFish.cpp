#include "GoldFish.hpp"

GoldFish::GoldFish(Renderer const& r, std::string s, Vector2D<int> coord, float const& z) : Fish(r, "sprites/fish/Goldfish.png" , coord, z) {
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
