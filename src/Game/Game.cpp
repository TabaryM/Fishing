#include "Game.hpp"

Game::Game(Initializer& i) : s(i) {

}

Game::~Game() {

}

void Game::mainLoop(){
  double actualTime = SDL_GetTicks();
  double lastTime = actualTime;

  Texture t(s.getRenderer(), new Surface(100, 100 , 120, 220, 30, 255), 100, 100);
  Texture fish(s.getRenderer(), new Surface(50, 90, 30, 120, 200, 255), 500, 400);


  while(!i.isQuit()){
    actualTime = SDL_GetTicks();
    if (actualTime - lastTime <= 1000.0 / 60.0){
      SDL_Delay(1000.0 / 60.0 - (actualTime - lastTime));
      actualTime = SDL_GetTicks();
    }
    lastTime = actualTime;

    i.update();

    s.clear();

    s.draw(t);
    s.draw(fish);

    s.update();
  }
}
