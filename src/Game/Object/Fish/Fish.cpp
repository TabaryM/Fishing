#include "Fish.hpp"

Fish::Fish(Renderer const& r, std::string sprite , Vector2D<int> const& coord, float const& z) : Object(r, new Surface(sprite), coord, z), direction(0.0) {
  this->right = rand() % 2;
  this->direction = rand() % 4 + 1;
  if(right == 1){
    this->direction = - this->direction;
  }
  this->degre = (rand() % 21 - 15)/10;
}

Fish::~Fish(){
}

float Fish::getDir(){
  return this->direction;
}

void Fish::setDir(float d){
  this->direction = d;
}

void Fish::setRight(int r){
  this->right = r;
  if(r == 1){
    this->direction = - this->direction;
  }
}

int Fish::getRight(){
  return this->right;
}

void Fish::setDegre(float d){
  this->degre = d;
}

float Fish::getDegre(){
  return this->degre;
}

int Fish::getType() {
  return FISH;
}
