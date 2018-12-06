#include "Fish.hpp"

Fish::Fish(Renderer const& r , Vector2D<int> const& coord, float const& z, int typeFish) : Object(r, new Surface(getSprite(typeFish)), coord, z) {
  this->right = rand() % 2;
  this->speedX = 2;
  if(!right){
    speedX = -speedX;
  }
  this->speedY = 0;
  this->hooked = false;
  this->typeFish = typeFish;
}


Fish::~Fish(){
}

int Fish::getSpeedX(){
  return this->speedX;
}

void Fish::setRight(bool r){
    
  if(r){
    if(this->getRight()){
      this->speedX = - this->speedX;
      this->right = r;
    }
  }
  if(!r){
    if(this->getRight() == 1){
      this->speedX = - this->speedX;
      this->right = r;
    }
  }
}

bool Fish::getRight(){
  return this->right;
}

void Fish::setSpeedY(int d){
  this->speedY = d;
}

int Fish::getSpeedY(){
  return this->speedY;
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
