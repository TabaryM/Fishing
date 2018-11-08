#include "Fish.hpp"

Fish::Fish(Renderer const& r , Vector2D<int> const& coord, float const& z, int type) : Object(r, new Surface(getSprite(type)), coord, z), direction(0.0) {
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

std::string Fish::getSprite(int type){
  std::string res;
  switch(type){
    case 1 :
      res = "sprites/fish/Normalfish.png" ;
      break ;
    case 2 :
      res = "sprites/fish/Goldfish.png" ;
      break ;
    case 3 :
      res = "sprites/fish/Fastfish.png" ;
      break ;
    case 4 :
      res = "sprites/fish/Ripfish.png" ;
      break ;
    case 5 :
      res = "sprites/fish/Bombfish.png" ;
      break ;
    case 6 :
      res = "sprites/fish/Jebaifish.png" ;
      break ;
    }
  return res;
}
