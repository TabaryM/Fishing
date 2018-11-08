#include "JebaiFish.hpp"

JebaiFish::JebaiFish(Renderer const& r, Vector2D<int> coord, float const& z) : Fish(r, coord, z, 6) {
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

void JebaiFish::setDegre(float d){
  setDegre(d);
}

float JebaiFish::getDegre(){
  return getDegre();
}
