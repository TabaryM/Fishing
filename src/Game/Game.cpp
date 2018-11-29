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
  std::cout << "start load" << std::endl;
  std::cout << "ScoreValue : " << gManager.getScore()->getValue() << " TimerValue : " << gManager.getTimer()->getValue() << std::endl;
  sManager.load(gManager.getFishs(), gManager.getScore(), gManager.getTimer());
  std::cout << "start fillFish" << std::endl;
  gManager.fillFish();
  std::cout << "fillFish end" << std::endl;

  std::cout << "creating gManager" << std::endl;
  gManager.create();
  std::cout << "creating iManager" << std::endl;
  iManager.create();
  std::cout << "iManager created" << std::endl;

  while(!i.isQuit()){
    actualTime = SDL_GetTicks();
    if (actualTime - lastTime <= 1000.0 / 60.0){
      SDL_Delay(1000.0 / 60.0 - (actualTime - lastTime));
      actualTime = SDL_GetTicks();
    }
    lastTime = actualTime;
    i.update();
    if (i.isActive(SDL_SCANCODE_P) || gManager.getTimer()->getValue() <= 0 ){
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

  sManager.save(gManager.getScore()) ;
  gManager.destroy();
  iManager.destroy();
}
