#include "Game.hpp"

Game::Game(Initializer& init) : s(init), gManager(&s,&i) , iManager(&s, &i) {}

void Game::launch(){
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
    gManager.update();

    s.clear();
    gManager.render();
    s.update();
  }

  gManager.destroy();
  iManager.destroy();
}
