#include "NormalFish.hpp"

NormalFish::NormalFish(Renderer const& r, Vector2D<int> coord, float const& z) : Fish(r, coord, z, 1) {
this->valeur = 2;
  this->speedX = Fish::getSpeedX();
  this->speedY = Fish::getSpeedY();
  this->right = Fish::getRight();
  this->timeDir = (rand()% 201) + 1;
}

NormalFish::~NormalFish(){
}

int NormalFish::getSpeedX(){
  return this->speedX;
}

void NormalFish::setSpeedX(int dx){
  this->speedX = dx;
}

int NormalFish::getValue(){
  return this->valeur;
}

void NormalFish::setSpeedY(int dy){
  this->speedY = dy;
}

int NormalFish::getSpeedY(){
  return this->speedY;
}

void NormalFish::setRight(bool r){
  
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

bool NormalFish::getRight(){
  return this->right;
}


void NormalFish::Brain(int br, int bd, int px,int py){
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
  
  
int NormalFish::collision(int br, int bd, int px,int py){ 
  
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

void NormalFish::dirChange(int time,int cas){

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

void NormalFish::goUpDown(){
  this->setSpeedY(-this->getSpeedY());
}
