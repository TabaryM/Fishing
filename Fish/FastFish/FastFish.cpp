#include "FastFish.hpp"

FastFish::FastFish(Renderer const& r, Vector2D<int> coord, float const& z) : Fish(r, coord, z, 3) {
  this->valeur = 2;
  this->speedX = Fish::getSpeedX();
  this->speedY = Fish::getSpeedY();
  this->right = Fish::getRight();
  this->timeSpeed = (rand()% 201) + 1;
  this->timeDir = (rand()% 201) + 1;
}

FastFish::~FastFish(){
}

int FastFish::getSpeedX(){
  return this->speedX;
}

void FastFish::setSpeedX(int dx){
  this->speedX = dx;
}

int FastFish::getValue(){
  return this->valeur;
}

void FastFish::setSpeedY(int dy){
  this->speedY = dy;
}

int FastFish::getSpeedY(){
  return this->speedY;
}

void FastFish::setRight(bool r){
  
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

bool FastFish::getRight(){
  return this->right;
}


Vector2D<int> FastFish::Brain(int br, int bd, int px,int py){
  int cas = this->collision(br,bd,px,py);
  if(cas == 0){
    this->speedChange(this->timeSpeed);
    this->dirChange(this->timeDir,0);
    return Vector2D<int>(this->getSpeedX(),this->getSpeedY());
  }
  if(cas == 1){
    this->speedChange(this->timeSpeed);
    this->dirChange(this->timeDir,1);
    return Vector2D<int>(this->getSpeedX(),this->getSpeedY());
  }
  if(cas == 2){
    this->speedChange(this->timeSpeed);
    this->dirChange(this->timeDir,0);
    this->goUpDown();
    return Vector2D<int>(this->getSpeedX(),this->getSpeedY());
  }
  if(cas == 3){
    this->speedChange(this->timeSpeed);
    this->dirChange(this->timeDir,0);
    return Vector2D<int>((this->getSpeedX() * 0.5),this->getSpeedY());
  }
  if(cas == 4){
    this->speedChange(this->timeSpeed);
    this->dirChange(this->timeDir,0);
    return Vector2D<int>(this->getSpeedX(),(this->getSpeedY() * 0.5));
  }
  return Vector2D<int>(0,0);
}
  
  
int FastFish::collision(int br, int bd, int px,int py){ 
  
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

void FastFish::speedChange(int time){
  
  if(time == 0){
    if(this->getSpeedX() == 4){
      this->timeSpeed = (rand() % 101) + 1; 
      this->setSpeedX(2);
    }else{
      this->timeSpeed = (rand() % 201) + 1;
      this->setSpeedX(4);
    }
    this->setSpeedY(1);
  }
  this->timeSpeed--;
}
 
void FastFish::dirChange(int time,int cas){

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

void FastFish::goUpDown(){
  this->setSpeedY(-this->getSpeedY());
}


  
  
  
  

