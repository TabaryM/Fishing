#include "Game.hpp"

Game::Game(Initializer& init) : s(init), gManager(&s,&i), iManager(&s, &i), sManager(&s) {}

void Game::launch(){
  i.isFlip(SDL_SCANCODE_P);
  srand (time(NULL));
  double actualTime = SDL_GetTicks();
  double lastTime = actualTime;

  //Initialize Score and Timer
  gManager.initST() ;

  //Load level information from txt
  sManager.load(gManager.getFishs(), gManager.getScore(), gManager.getTimer());
  gManager.fillFish();

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

    iManager.setPause(i.isActive(SDL_SCANCODE_P));
    iManager.setWin((gManager.getTimer()->getValue() <= 0) && (gManager.getScore()->getGoal() <= gManager.getScore()->getValue()));
    iManager.setLose((gManager.getTimer()->getValue() <= 0) && (gManager.getScore()->getGoal() > gManager.getScore()->getValue()));

    if (iManager.getUpdate()) {
      iManager.update();
    } else {
      gManager.update();
    }

    s.clear();
    gManager.render();
    if (iManager.getUpdate()){
      iManager.render();
    }
    s.update();
  }

  sManager.save(gManager.getScore()) ;
  gManager.destroy();
  iManager.destroy();
}
