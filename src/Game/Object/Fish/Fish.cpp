#include "Fish.hpp"

Fish::Fish(Renderer const& r , Vector2D<int> const& coord, float const& z, int typeFish) : Object(r, new Surface(getSprite(typeFish)), coord, z), direction(0.0) {
  this->right = rand() % 2;
  this->direction = rand() % 4 + 1;
  if(right == 1){
    this->direction = - this->direction;
  }
  this->degre = (rand() % 21 - 15)/10;
  this->hooked = false;
  this->hitbox = new Object(r,new Surface(Vector2D<int>(20,40),(char)0, (char)0, (char)0, (char)255),Vector2D<int>(coord.getX(),coord.getY()-20+this->getH()/2), 10);
  this->link(hitbox);
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

void Fish::setHook(){
  this->hooked = true;
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

bool const& Fish::isHooked() const{
  return hooked;
}

int Fish::getTypeFish() {
  return typeFish ;
}

Texture& Fish::getHitbox(){
  return hitbox->getTexture() ;
}
