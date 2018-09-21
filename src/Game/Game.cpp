#include "Game.hpp"

Game::Game(Initializer& i) : s(i) {

}

Game::~Game() {

}

void Game::mainLoop(){
  double actualTime = SDL_GetTicks();
  double lastTime = actualTime;

  Texture sky(s.getRenderer(), new Surface(1280, 180 , 0, 20, 100, 255), 0, 0);
  Texture fish(s.getRenderer(), new Surface(45, 20, 30, 60, 200, 255), 500, 400);

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
    s.draw(fish);

    s.update();
  }
}
