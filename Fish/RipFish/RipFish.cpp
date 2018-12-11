#include "RipFish.hpp"

RipFish::RipFish(Renderer const& r, Vector2D<int> coord, float const& z) : Fish(r, coord, z, 4) {
 this->valeur = 2;
  this->speedX = Fish::getSpeedX();
  this->speedY = Fish::getSpeedY();
  this->right = Fish::getRight();
  this->timeDir = (rand()% 201) + 1;
}

RipFish::~RipFish(){
}

int RipFish::getSpeedX(){
  return this->speedX;
}

void RipFish::setSpeedX(int dx){
  this->speedX = dx;
}

int RipFish::getValue(){
  return this->valeur;
}

void RipFish::setSpeedY(int dy){
  this->speedY = dy;
}

int RipFish::getSpeedY(){
  return this->speedY;
}

void RipFish::setRight(bool r){
  
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

bool RipFish::getRight(){
  return this->right;
}


void RipFish::Brain(int br, int bd, int px,int py){
  int cas = this->collision(br,bd,px,py);

  if(cas == 0){
    this->dirChange(this->timeDir,0);
  }
  if(cas == 1){
    this->dirChange(this->timeDir,1);

  }
  if(cas == 2){
    this->dirChange(this->timeDir,0);
    this->goUpDown();
  }
  if(cas == 3){
    this->dirChange(this->timeDir,0);
  }
  if(cas == 4){
    this->dirChange(this->timeDir,0);
  }
}
  
  
int RipFish::collision(int br, int bd, int px,int py){ 
  
  if(px + getSpeedX() > br - 20 && right){return 3;}
  if(px + getSpeedX() < 20 && !right){return 3;}
  if(py + getSpeedY() > bd - 20){return 4;}
  if(py + getSpeedY() < 220){return 4;}
  
  if(px + getSpeedX() > br && right){return 1;}
  if(px + getSpeedX() < 0 && !right){return 1;}
  if(py + getSpeedY() > bd){return 2;}
  if(py + getSpeedY() < 200){return 2;}
  
  return 0;
  
}

void RipFish::dirChange(int time,int cas){

  if(time == 0){
    if(this->getRight()){
      this->setRight(false);
    }else{
      this->setRight(true);
    }
  }
  if(cas == 0){
    this->timeDir--;
  }
}

void RipFish::goUpDown(){
  this->setSpeedY(-this->getSpeedY());
}
