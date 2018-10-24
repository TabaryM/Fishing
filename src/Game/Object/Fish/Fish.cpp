#include "Fish.hpp"

Fish::Fish(Renderer const& r, std::string s, int const& x, int const& y, float const& z) : Object(r, new Surface(s), x, y, z), direction(0.0) {
  this->right = rand() % 2;
  this->direction = rand() % 5 + 1;
  if(right == 1){
    this->direction = - this->direction; 
  }
}

Fish::~Fish(){
}

float Fish::getDir(){
  return this->direction;
}

void Fish::setDir(float d){
  this->direction = d;
}

