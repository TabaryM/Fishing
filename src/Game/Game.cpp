#include "Game.hpp"

Game::Game(Initializer& init) : s(init), gManager(&s,&i) , iManager(&s, &i) {}

void Game::launch(){
  i.isFlip(SDL_SCANCODE_P);
  srand (time(NULL));
  double actualTime = SDL_GetTicks();
  double lastTime = actualTime;

  gManager.create();
  iManager.create();

  while(!i.isQuit()){
    actualTime = SDL_GetTicks();
    if (actualTime - lastTime <= 1000.0 / 60.0){
      SDL_Delay(1000.0 / 60.0 - (actualTime - lastTime));
      actualTime = SDL_GetTicks();
    }
    lastTime = actualTime;

    i.update();
    if (i.isActive(SDL_SCANCODE_P)){
      iManager.update();
    } else {
      gManager.update();
    }

    s.clear();
    gManager.render();
    if (i.isActive(SDL_SCANCODE_P)){
      iManager.render();
    }
    s.update();
  }

  gManager.destroy();
  iManager.destroy();
}
