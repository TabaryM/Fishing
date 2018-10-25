#include "GameManager.hpp"


GameManager::GameManager(Stage* s, Input* i) : Manager(s, i), speed(1), borders(1280,720) {}

void GameManager::create(){
  objets["Ocean"] = new Object(s->getRenderer(), new Surface(borders.getW(), borders.getH() *0.8, 50, 150, 230, 255), 0, borders.getH()*0.2, 2);
  objets["Ciel"] = new Object(s->getRenderer(), new Surface(borders.getW(), borders.getH() *0.2 , 85, 205, 235, 255), 0, 0, 1);
  objets["Bateau"] = new Boat(s->getRenderer(), 500, 100, 3);
  objets["Hook"] = new Hook(s->getRenderer(), objets["Bateau"]->getX() + 0.5 * objets["Bateau"]->getW() , objets["Bateau"]->getY() + 50 , objets["Bateau"]->getZ());
  objets["Kappa"] = new Object(s->getRenderer(), new Surface("sprites/Kappa.png"), objets["Bateau"]->getX() + 0.5 * objets["Bateau"]->getW(), objets["Bateau"]->getY() - 50 , objets["Bateau"]->getZ());

  objets["Bateau"]->link(objets["Kappa"]);
  objets["Bateau"]->link(objets["Hook"]);

  for (int i = 0; i < 10; i++) {
    objets["Fish" + std::to_string(i)] = new Fish(s->getRenderer(), 500, 200 + 50 * i, i + 10);
  }
  Manager::create();
}

void GameManager::update(){
  Manager::update();
  for (int i = 0; i < 10; i++) {
    objets["Fish" + std::to_string(i)]->move(1 * static_cast <Fish*> (objets["Fish" + std::to_string(i)])->getDir(), 0.5 * static_cast <Fish*> (objets["Fish" + std::to_string(i)])->getDir());
  }

  updateControlX(objets["Bateau"]);
  updateControlY(objets["Hook"]);
}

void GameManager::render(){
  Manager::render();
}

void GameManager::destroy(){
}


void GameManager::updateControlX(Object* obj) {
  int depX = 0;
  int depY = 0;

  if (i->getKeyKB(SDL_SCANCODE_A)) {
    if (obj->getX() -speed <= 0 ) {
      depX -= obj->getX();
    }
    else{
      depX -= speed;
    }
  }

  if (i->getKeyKB(SDL_SCANCODE_D)) {
    if (obj->getX() + obj->getW() + speed >= 1280) {
      depX += 1280 - obj->getW() - obj->getX();
    }
    else{
      depX += speed;
    }
  }

  if (i->getKeyKB(SDL_SCANCODE_E)) {
    speed++;
  }
  if (i->getKeyKB(SDL_SCANCODE_R)) {
    if (speed > 1) {
      speed--;
    }
  }

  obj->move(depX, depY);

}
void GameManager::updateControlY(Object* obj) {
  int depX = 0;
  int depY = 0;

  if (i->getKeyKB(SDL_SCANCODE_W)) {
      if (obj->getY() - speed <= 150 ) {
        depY -= obj-> getY() - 150 ;
      }
      else{
        depY -= speed;
      }
  }

  if (i->getKeyKB(SDL_SCANCODE_S)) {
    if (obj->getY() + obj->getH() + speed >= 720) {
      depY += 720 - obj->getY() - obj->getH();
    }
    else{
      depY += speed;
    }
  }

  obj->move(depX, depY);

}