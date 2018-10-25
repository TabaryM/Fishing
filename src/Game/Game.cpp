#include "Game.hpp"

Game::Game(Initializer& init) : s(init), gManager(&s,&i) , iManager(&s, &i) {}

void Game::launch(){
  srand (time(NULL));
  double actualTime = SDL_GetTicks();
  double lastTime = actualTime;

  gManager.create();
  iManager.create();
  i.isFlip(SDL_SCANCODE_P)

  while(!i.isQuit()){
    actualTime = SDL_GetTicks();
    if (actualTime - lastTime <= 1000.0 / 60.0){
      SDL_Delay(1000.0 / 60.0 - (actualTime - lastTime));
      actualTime = SDL_GetTicks();
    }
    lastTime = actualTime;

    i.update();
    gManager.update();
    if (gManager.getPause()){
      iManager.update();
    }

    s.clear();
    gManager.render();
    if (gManager.getPause()){
      iManager.render();
    }
    s.update();
  }

  gManager.destroy();
  iManager.destroy();
}
