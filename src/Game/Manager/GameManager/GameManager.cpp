#include "GameManager.hpp"


GameManager::GameManager(Stage* s, Input* i) : Manager(s, i), speed(1), borders(1280,720) {}

void GameManager::create(){
  objets["Ocean"] = new Object(s->getRenderer(), new Surface(borders.getW(), borders.getH() *0.8, 0, 102, 204, 255), 0, borders.getH()*0.22, 2);
  objets["Ciel"] = new Object(s->getRenderer(), new Surface("sprites/Sky.png"), 0, 0, 1);
  objets["Bateau"] = new Boat(s->getRenderer(), 500, 100, 3);
  objets["Hook"] = new Hook(s->getRenderer(), objets["Bateau"]->getX() + 0.5 * objets["Bateau"]->getW() , objets["Bateau"]->getY() + 60 ,5);
  objets["Kappa"] = new Object(s->getRenderer(), new Surface("sprites/Kappa.png"), objets["Bateau"]->getX() + 0.82 * objets["Bateau"]->getW(), objets["Bateau"]->getY() - 46 , objets["Bateau"]->getZ());
  objets["FishPole"] = new Object(s->getRenderer(), new Surface("sprites/FishPole.png"), objets["Kappa"]->getX()-98, objets["Kappa"]->getY()-50 , objets["Bateau"]->getZ());


  objets["Bateau"]->link(objets["Kappa"]);
  objets["Kappa"]->link(objets["FishPole"]);
  objets["FishPole"]->link(objets["Hook"]);

  for (int i = 0; i < 10; i++) {
    objets["Fish" + std::to_string(i)] = new Fish(s->getRenderer(), 500, 200 + 50 * i, 4);
  }
  for (int i = 0; i < 14; i++) {
    objets["Wave" + std::to_string(i)] = new Wave(s->getRenderer(), -98.5 + 98.5 * i, 143, 3.05);
  }
  Manager::create();
}

void GameManager::update(){
  for (int i = 0; i < 10; i++) {
    objets["Fish" + std::to_string(i)]->move(1 * static_cast <Fish*> (objets["Fish" + std::to_string(i)])->getDir(), 0.5 * static_cast <Fish*> (objets["Fish" + std::to_string(i)])->getDir());
  }
  //the swell
  for (int i = 0; i < 14; i++) {
    if(objets["Wave" + std::to_string(i)]->getX() >=1280 ){
      objets["Wave" + std::to_string(i)]->move(-1280-98.5,0);
    }
    objets["Wave" + std::to_string(i)]->move(1,0);
  }

  updateControlX(objets["Bateau"]);
  updateControlY(objets["Hook"]);
}

void GameManager::render(){
  Manager::render();
  s->draw(objets["Hook"]->getX() + 0.5*objets["Hook"]->getW() , objets["Hook"]->getY() +0.15*objets["Hook"]->getH(), objets["FishPole"]->getX(), objets["FishPole"]->getY());
}

void GameManager::destroy(){
}

void GameManager::updateControlX(Object* obj) {
  int depX = 0;
  int depY = 0;

  if (i->isActive(SDL_SCANCODE_A)) {
    if (obj->getX() -speed <= 0 ) {
      depX -= obj->getX();
    }
    else{
      depX -= speed;
    }
  }

  if (i->isActive(SDL_SCANCODE_D)) {
    if (obj->getX() + obj->getW() + speed >= 1280) {
      depX += 1280 - obj->getW() - obj->getX();
    }
    else{
      depX += speed;
    }
  }

  if (i->isActive(SDL_SCANCODE_E)) {
    speed++;
  }
  if (i->isActive(SDL_SCANCODE_R)) {
    if (speed > 1) {
      speed--;
    }
  }

  obj->move(depX, depY);

}
void GameManager::updateControlY(Object* obj) {
  int depX = 0;
  int depY = 0;

  if (i->isActive(SDL_SCANCODE_W)) {
      if (obj->getY() - speed <= 0 ) {
        depY -= obj-> getY() ;
      }
      else{
        depY -= speed;
      }
  }

  if (i->isActive(SDL_SCANCODE_S)) {
    if (obj->getY() + obj->getH() + speed >= 720) {
      depY += 720 - obj->getY() - obj->getH();
    }
    else{
      depY += speed;
    }
  }

  obj->move(depX, depY);

}
