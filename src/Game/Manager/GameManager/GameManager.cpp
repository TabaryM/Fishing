#include "GameManager.hpp"


GameManager::GameManager(Stage* s, Input* i) : Manager(s, i), speed(1), borders(Vector2D<int>(Window::WIDTH, Window::HEIGHT)) {}

void GameManager::create(){
  objets["Ciel"] = new Object(s->getRenderer(), new Surface("sprites/Sky.png"), Vector2D<int>(0, 0), 1);
  objets["Ocean"] = new Object(s->getRenderer(), new Surface(Vector2D<int>(borders.getSize().getX(), borders.getSize().getY() *0.8), (char)0, (char)102, (char)204, (char)255), Vector2D<int>(0, borders.getSize().getY()*0.22), 2);
  objets["Bateau"] = new Boat(s->getRenderer(), Vector2D<int>(500, 100), 3);
  objets["Hook"] = new Hook(s->getRenderer(), Vector2D<int>(objets["Bateau"]->getX() + 0.5 * objets["Bateau"]->getSize().getX() , objets["Bateau"]->getY() + 60 ),5);
  objets["Kappa"] = new Object(s->getRenderer(), new Surface("sprites/Kappa.png"), Vector2D<int>(objets["Bateau"]->getX() + 0.82 * objets["Bateau"]->getSize().getX(), objets["Bateau"]->getY() - 46) , objets["Bateau"]->getZ());
  objets["FishPole"] = new Object(s->getRenderer(), new Surface("sprites/FishPole.png"), Vector2D<int>(objets["Kappa"]->getX()-98, objets["Kappa"]->getY()-50) , objets["Bateau"]->getZ());

  ///////////////////////test wave
  objets["Wave"] = new Object(s->getRenderer(), new Surface("sprites/Wave.png"), Vector2D<int>(500, 143), 3.05); //pos y via constante ?
  ////////////////////////////////////

  objets["Bateau"]->link(objets["Kappa"]);
  objets["Kappa"]->link(objets["FishPole"]);
  objets["FishPole"]->link(objets["Hook"]);

  for (int i = 0; i < 10; i++) {
    objets["Fish" + std::to_string(i)] = new Fish(s->getRenderer(), Vector2D<int>(500, 200 + 50 * i), i + 10);
  }
  Manager::create();
}

void GameManager::update(){
  for (int i = 0; i < 10; i++) {
    objets["Fish" + std::to_string(i)]->move(Vector2D<int>(1 * static_cast <Fish*> (objets["Fish" + std::to_string(i)])->getDir(), 0.5 * static_cast <Fish*> (objets["Fish" + std::to_string(i)])->getDir()));
  }

  updateControlX(objets["Bateau"]);
  updateControlY(objets["Hook"]);
  for (auto& it1 : objets){
    for (auto& it2 : objets) {
        it1.second->collide([&](Object* o1, Object* o2) {
          if (o1->getType() == HOOK && o2->getType() == FISH) {
            std::cout << "Catch a fish" << std::endl;
            o1->link(o2);
          }
        }, it2.second);
    }
  }
}

void GameManager::render(){
  Manager::render();
  //dessine la ligne
  s->draw(objets["Hook"]->getX() + 0.5*objets["Hook"]->getW() , objets["Hook"]->getY() +0.15*objets["Hook"]->getH(), objets["FishPole"]->getX(), objets["FishPole"]->getY());
}

void GameManager::destroy(){
}

void GameManager::updateControlX(Object* obj) {
  Vector2D<int> dep;

  if (i->isActive(SDL_SCANCODE_A)) {
    if (obj->getX() -speed <= 0 ) {
      dep.setX(dep.getX() - obj->getX());
    }
    else{
      dep.setX(dep.getX() - speed);
    }
  }

  if (i->isActive(SDL_SCANCODE_D)) {
    if (obj->getX() + obj->getW() + speed >= Window::WIDTH) {
      dep.setX(dep.getX() + Window::WIDTH - obj->getW() - obj->getX());
    }
    else{
      dep.setX(dep.getX() + speed);
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

  obj->move(dep);

}
void GameManager::updateControlY(Object* obj) {
  Vector2D<int> dep;

  if (i->isActive(SDL_SCANCODE_W)) {
      if (obj->getY() - speed <= 150 ) {
        dep.setY(150 - obj->getY() - speed);
      }
      else{
        dep.setY(dep.getY() - speed);
      }
  }

  if (i->isActive(SDL_SCANCODE_S)) {
    if (obj->getY() + obj->getH() + speed >= Window::HEIGHT) {
      dep.setY(dep.getY() + Window::HEIGHT - obj->getY() - obj->getH());
    }
    else{
      dep.setY(dep.getY() + speed);
    }
  }

  obj->move(dep);

}
