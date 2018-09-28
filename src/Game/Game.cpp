#include "Game.hpp"

Game::Game(Initializer& i) : s(i), speed(1) {

}

Game::~Game() {
  for (auto& o : objets) {
    delete o.second;
  }
}

void Game::mainLoop(){
  double actualTime = SDL_GetTicks();
  double lastTime = actualTime;

<<<<<<< HEAD
  objets.push_back(new Object(s.getRenderer(), new Surface(1280, 540, 0, 50, 225, 255), 0, 180));
  objets.push_back(new Object(s.getRenderer(), new Surface(1280, 180 , 20, 80, 150, 255), 0, 0));
  objets.push_back(new Object(s.getRenderer(), new Surface("Kappa.png"), 500, 400));
  objets.push_back(new Fish(s.getRenderer(),100,100));
  objets.push_back(new Boat(s.getRenderer(),500,500));
  
=======
  objets["Ocean"] = new Object(s.getRenderer(), new Surface(1280, 540, 0, 50, 225, 255), 0, 180, 2);
  objets["Ciel"] = new Object(s.getRenderer(), new Surface(1280, 180 , 20, 80, 150, 255), 0, 0, 1);
  objets["Kappa"] = new Object(s.getRenderer(), new Surface("Kappa.png"), 500, 400, 4);
  objets["Fish"] = new Fish(s.getRenderer(),100,100, 3);

  sortObject();
>>>>>>> Control

  while(!i.isQuit()){
    actualTime = SDL_GetTicks();
    if (actualTime - lastTime <= 1000.0 / 60.0){
      SDL_Delay(1000.0 / 60.0 - (actualTime - lastTime));
      actualTime = SDL_GetTicks();
    }
    lastTime = actualTime;

    updateControl();
    s.clear();

    for (Object* o : draws) {
        s.draw(*o);
    }
    s.update();
  }
}

void Game::updateControl() {
  i.update();

  if (i.getKeyKB(SDL_SCANCODE_A)) {
    if (objets["Kappa"]->getX() > speed) {
      objets["Kappa"]->setX(objets["Kappa"]->getX() - speed);
    }
  }

  if (i.getKeyKB(SDL_SCANCODE_D)) {
    if (objets["Kappa"]->getX() < (1280 - objets["Kappa"]->getW()) - speed) {
      objets["Kappa"]->setX(objets["Kappa"]->getX() + speed);
    }
  }

  if (i.getKeyKB(SDL_SCANCODE_W)) {
    if (objets["Kappa"]->getY() > speed) {
      objets["Kappa"]->setY(objets["Kappa"]->getY() - speed);
    }
  }

  if (i.getKeyKB(SDL_SCANCODE_S)) {
    if (objets["Kappa"]->getY() < (720 - objets["Kappa"]->getH()) - speed) {
      objets["Kappa"]->setY(objets["Kappa"]->getY() + speed);
  }
  if (i.getKeyKB(SDL_SCANCODE_E)) {
    speed++;
  }
  if (i.getKeyKB(SDL_SCANCODE_R)) {
    if (speed > 1) {
      speed--;
    }
  }
}

void Game::sortObject() {
  for (auto& o : objets) {
      draws.push_back(o.second);
  }
  std::sort(draws.begin(), draws.end(), Object::ObjectCompare());
}
