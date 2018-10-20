#include "Game.hpp"

Game::Game(Initializer& i) : s(i), speed(1), borders(1280,720) {

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

  objets["Ocean"] = new Object(s.getRenderer(), new Surface(borders.getW(), borders.getH() *0.8, 0, 0, 128, 255), 0, borders.getH()*0.2, 2);
  objets["Ciel"] = new Object(s.getRenderer(), new Surface(borders.getW(), borders.getH() *0.2 , 0, 142, 204, 255), 0, 0, 1);
  objets["Bateau"] = new Boat(s.getRenderer(), 500, 130, 3);
  objets["Hook"] = new Hook(s.getRenderer(), objets["Bateau"]->getX() + 20, objets["Bateau"]->getY() + 50 , objets["Bateau"]->getZ());
  objets["Kappa"] = new Object(s.getRenderer(), new Surface("sprites/Kappa.png"), objets["Bateau"]->getX() + 20, objets["Bateau"]->getY() - 50 , objets["Bateau"]->getZ());


  for (int i = 0; i < 10; i++) {
    objets["Fish" + std::to_string(i)] = new Fish(s.getRenderer(), 500, 200 + 50 * i, i + 10);
  }

  objets["Bateau"]->link(objets["Kappa"]);
  objets["Bateau"]->link(objets["Hook"]);


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

    // boucle pause

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
    if (obj->getX() -speed <= 0 ) {
      depX -= obj->getX();
    }
    else{
      depX -= speed;
    }
  }

  if (i.getKeyKB(SDL_SCANCODE_D)) {
    if (obj->getX() + obj->getW() + speed >= 1280) {
      depX += 1280 - obj->getW() - obj->getX();
    }
    else{
      depX += speed;
    }
  }

  if (i.getKeyKB(SDL_SCANCODE_W)) {
    if (obj->getY() - speed <= 0 ) {
      depY -= obj->getY();
    }
    else{
      depY -= speed;
    }
  }

  if (i.getKeyKB(SDL_SCANCODE_S)) {
    if (obj->getY() + obj->getH() + speed >= 720) {
      depY += 720 - obj->getY() - obj->getH();
    }
    else{
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
