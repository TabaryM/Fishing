#include "Game.hpp"

Game::Game(Initializer& i) : s(i) {

}

Game::~Game() {

}

void Game::mainLoop(){
  double actualTime = SDL_GetTicks();
  double lastTime = actualTime;

  Texture sky(s.getRenderer(), new Surface(1280, 180 , 20, 80, 150, 255), 0, 0);
  Object fish(s.getRenderer(), new Surface("Kappa.png"), 500, 400);
  Texture ocean(s.getRenderer(), new Surface(1280, 540, 0, 50, 225, 255), 0, 180);
  Fish f1(s.getRenderer(),100,100);

  while(!i.isQuit()){
    actualTime = SDL_GetTicks();
    if (actualTime - lastTime <= 1000.0 / 60.0){
      SDL_Delay(1000.0 / 60.0 - (actualTime - lastTime));
      actualTime = SDL_GetTicks();
    }
    lastTime = actualTime;

    i.update();
    s.clear();

    s.draw(sky);
    s.draw(ocean);
    s.draw(fish);
    s.draw(f1);

    s.update();
  }
}
