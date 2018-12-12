#include "Fish.hpp"

Fish::Fish(Renderer const& r , Vector2D<int> const& coord, float const& z, int typeFish) : Object(r, new Surface(getSprite(typeFish)), coord, z) {
  
  this->right = rand() % 2;
  this->speedX = 2;
  if(typeFish == 5){
    this->speedX = 1;
  }
  
  if(!right){
    speedX = -speedX;
  }
  this->speedY = (rand() % 3) - 1;
  this->hooked = false;
  this->typeFish = typeFish;
  this->timeDir = (rand()% 501) + 1000;
  this->timeSpeed = (rand()% 201) + 500;
  this->timeupdown = (rand()% 201) + 250;
  this->hitbox = new Hitbox(r,Vector2D<int>(coord.getX(),coord.getY()-20+this->getH()/2), 10);
  static_cast<Object*> (this)->link(static_cast<Object*> (hitbox));
  
}

Fish::~Fish(){
}

int Fish::getSpeedX(){
  return this->speedX;
}

void Fish::setSpeedX(int dx){
  this->speedX = dx;
}

void Fish::setRight(bool r){
    
  if(r){
    if(!this->getRight()){
      this->speedX = - this->speedX;
      this->right = r;
    }
  }
  if(!r){
    if(this->getRight()){
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

void Fish::getPoints(Renderer const& r, Score* s){
  int res = 0 ;
  int swich = getTypeFish() ;
  switch (swich) {
    case 1 :
      res = 1 ;
      break ;
    case 2 :
      res = 10 ;
      break ;
    case 3 :
      res = 2 ;
      break ;
    case 4 :
      res = -3 ;
      break ;
    case 5 :
      res = 0 /* TODO: trouver un comportement et une valeur */ ;
      break ;
    case 6 :
      res = 5 ;
      break ;
    }
    s->addScore(r, res) ;
}

int Fish::getPoints(){
    int res = 0 ;
    int swich = getTypeFish() ;
    switch (swich) {
      case 1 :
        res = 1 ;
        break ;
      case 2 :
        res = 10 ;
        break ;
      case 3 :
        res = 2 ;
        break ;
      case 4 :
        res = -3 ;
        break ;
      case 5 :
        res = 0 /* TODO: trouver un comportement et une valeur */ ;
        break ;
      case 6 :
        res = 5 ;
        break ;
    }
    return res;
}


Vector2D<int>* Fish::getCorner() {
  return hitbox->getCorner();
}

Rectangle Fish::getHitbox(){
  return hitbox->getHitbox() ;
}

Vector2D<int> Fish::Brain(int br, int bd, int hx, int hy, int hw, int hh){
  int cas = this->collision(br,bd,hx,hy,hw,hh);
  
  if(cas == 0){
    return Vector2D<int>(0,0);
  }
  
  if(cas == 1){
    if(typeFish == 3){
      this->speedChange(this->timeSpeed);
    }
    this->upDownChange(this->timeupdown);
    this->dirChange(this->timeDir,1);
    return Vector2D<int>(getSpeedX(),getSpeedY());
  }
  
  if(cas == 2){
    if(typeFish == 3){
      this->speedChange(this->timeSpeed);
    }
    this->upDownChange(this->timeupdown);
    this->dirChange(this->timeDir,0);
    this->goUpDown();
    
    return Vector2D<int>(getSpeedX(),getSpeedY());
  }
  
  if(cas == 3){
    if(typeFish == 3){
      this->speedChange(this->timeSpeed);
    }
    this->upDownChange(this->timeupdown);
    this->dirChange(this->timeDir,0);
    return Vector2D<int>(0.5 * getSpeedX(),getSpeedY());
  }
  
  if(cas == 4){
    if(typeFish == 3){
      this->speedChange(this->timeSpeed);
    }
    this->upDownChange(this->timeupdown);
    this->dirChange(this->timeDir,0);
    return Vector2D<int>(getSpeedX(),0.5 * getSpeedY());
  }
  
  if(typeFish == 3){
      this->speedChange(this->timeSpeed);
  }
  this->upDownChange(this->timeupdown);
  this->dirChange(this->timeDir,0);
  return Vector2D<int>(getSpeedX(),getSpeedY());
}
  
  
int Fish::collision(int br, int bd, int hx, int hy, int hw, int hh){ 
  
  if(isHooked()){return 0;}
  
  if(typeFish == 6){
    
    if(hx + hw < this->getX() && this->getX() < hx + hw + 50){return 1;}
    if(hx - 50 < this->getX() && this->getX() + this->getW() < hx){return 1;}
    if(hy + hh < this->getY() && this->getY() + this->getW() < hy + hw + 50){return 2;}
    if(hy - 50 < this->getY() && this->getY() < hy){return 2;}
    
  }
  
  if(this->getX() + getSpeedX() + this->getW() > br ){return 1;}
  if(this->getX() + getSpeedX() < 0 ){return 1;}
  if(this->getY() + getSpeedY() + this->getH() > bd){return 2;}
  if(this->getY() + getSpeedY() < 200){return 2;}
  
  if(this->getX() + getSpeedX() + this->getW() > br - 50 && this->right){return 3;}
  if(this->getX() + getSpeedX() < 50 && !this->right){return 3;}
  if(this->getY() + getSpeedY() + this->getH() > bd - 50){return 4;}
  if(this->getY() + getSpeedY() < 250){return 4;}
  
  return -1;
  
}

void Fish::dirChange(int time,int cas){

  if(time == 0 && cas == 0){
    if(this->getRight()){
      this->setRight(false);
    }else{
      this->setRight(true);
    }
    this->timeDir = (rand()% 501) + 1000;
  }
  this->timeDir--;
  
  if(cas == 1){
    if(this->getRight()){
      this->setRight(false);
    }else{
      this->setRight(true);
    }
  }
  
}
void Fish::speedChange(int time){
  
  if(time == 0){
    if(this->getSpeedX() == 6){
      this->timeSpeed = (rand() % 101) + 500; 
      this->setSpeedX(2);
    }else{
      this->timeSpeed = (rand() % 201) + 250;
      this->setSpeedX(6);
    }
  }
  this->timeSpeed--;
}
void Fish::upDownChange(int time){
  
  if(time == 0){
    this->goUpDown();
    this->timeupdown = (rand()% 201) + 250;
  }
  this->timeupdown--;
}


void Fish::goUpDown(){
  this->setSpeedY( - this->getSpeedY());
}
