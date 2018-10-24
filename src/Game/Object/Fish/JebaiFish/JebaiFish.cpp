#include "JebaiFish.hpp"

JebaiFish::JebaiFish(Renderer const& r, int const& x, int const& y, float const& z) : Fish(r, "sprites/fish/Jebaifish.png" , x, y, z) {
  this->valeur = 2;
}

JebaiFish::~JebaiFish(){
}

float JebaiFish::getDir(){
  return getDir();
}

void JebaiFish::setDir(float d){
  setDir(d);
}

int JebaiFish::getValue(){
  return this->valeur;
}