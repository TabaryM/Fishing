#include "Game.hpp"

Game::Game(Initializer& i) : s(i), speed(1) {

}

Game::~Game() {
  for (auto& o : objets) {
    delete o.second;
  }
}

void Game::mainLoop(){
  srand (time(NULL));
  double actualTime = SDL_GetTicks();
  double lastTime = actualTime;

  objets["Ocean"] = new Object(s.getRenderer(), new Surface(1280, 540, 0, 0, 128, 255), 0, 180, 2);
  objets["Ciel"] = new Object(s.getRenderer(), new Surface(1280, 180 , 0, 142, 204, 255), 0, 0, 1);
  objets["Bateau"] = new Boat(s.getRenderer(), 500, 130, 3);
  objets["Kappa"] = new Object(s.getRenderer(), new Surface("Kappa.png"), objets["Bateau"]->getX() + 20, objets["Bateau"]->getY() - 50 , objets["Bateau"]->getZ());

  for (int i = 0; i < 10; i++) {
    objets["Fish" + std::to_string(i)] = new Fish(s.getRenderer(), 500, 200 + 50 * i, i + 10);
  }

  objets["Bateau"]->link(objets["Kappa"]);

  sortObject();

  while(!i.isQuit()){
    actualTime = SDL_GetTicks();
    if (actualTime - lastTime <= 1000.0 / 60.0){
      SDL_Delay(1000.0 / 60.0 - (actualTime - lastTime));
      actualTime = SDL_GetTicks();
    }
    lastTime = actualTime;

    updateControl(objets["Bateau"]);
    s.clear();

    for (int i = 0; i < 10; i++) {
      objets["Fish" + std::to_string(i)]->move(1 * static_cast <Fish*> (objets["Fish" + std::to_string(i)])->getDir(), 0.5 * static_cast <Fish*> (objets["Fish" + std::to_string(i)])->getDir());
    }

    for (Object* o : draws) {
        s.draw(*o);
    }
    s.update();
  }
}

void Game::updateControl(Object* obj) {
  i.update();

  int depX = 0;
  int depY = 0;

  if (i.getKeyKB(SDL_SCANCODE_A)) {
    if (obj->getX() > speed) {
      depX -= speed;
    }
  }

  if (i.getKeyKB(SDL_SCANCODE_D)) {
    if (obj->getX() < (1280 - obj->getW()) - speed) {
      depX += speed;
    }
    
  }

  if (i.getKeyKB(SDL_SCANCODE_W)) {
    if (obj->getY() > speed) {
      depY -= speed;
    }
  }

  if (i.getKeyKB(SDL_SCANCODE_S)) {
    if (obj->getY() < (720 - obj->getH()) - speed) {
      depY += speed;
    }
  }
  if (i.getKeyKB(SDL_SCANCODE_E)) {
    speed++;
  }
  if (i.getKeyKB(SDL_SCANCODE_R)) {
    if (speed > 1) {
      speed--;
    }
  }

  obj->move(depX, depY);

}

void Game::sortObject() {
  for (auto& o : objets) {
      draws.push_back(o.second);
  }
  std::sort(draws.begin(), draws.end(), Object::ObjectCompare());
}
