#include "Game.hpp"

Game::Game(Initializer& i) : s(i) {

}

Game::~Game() {
  for (Object* o : objets) {
    delete o;
  }
}

void Game::mainLoop(){
  double actualTime = SDL_GetTicks();
  double lastTime = actualTime;

  objets.push_back(new Object(s.getRenderer(), new Surface(1280, 540, 0, 50, 225, 255), 0, 180));
  objets.push_back(new Object(s.getRenderer(), new Surface(1280, 180 , 20, 80, 150, 255), 0, 0));
  objets.push_back(new Object(s.getRenderer(), new Surface("Kappa.png"), 500, 400));
  objets.push_back(new Fish(s.getRenderer(),100,100));
  objets.push_back(new Boat(s.getRenderer(),500,500));
  

  while(!i.isQuit()){
    actualTime = SDL_GetTicks();
    if (actualTime - lastTime <= 1000.0 / 60.0){
      SDL_Delay(1000.0 / 60.0 - (actualTime - lastTime));
      actualTime = SDL_GetTicks();
    }
    lastTime = actualTime;

    updateControl();
    s.clear();

    for (Object* o : objets) {
        s.draw(*o);
    }
    s.update();
  }
}

void Game::updateControl() {
  i.update();
  if (i.getKeyKB(SDL_SCANCODE_A)){
    if (objets[2]->getTexture().getPosition().getX() > 1){
      objets[2]->setX(objets[2]->getTexture().getPosition().getX() - 1);
    }
  }
}
