#include "Game.hpp"

Game::Game(Initializer& init) : s(init), gManager(&s,&i), iManager(&s, &i), sManager(&s), lvl(0) {}

void Game::launch(){
  i.isFlip(SDL_SCANCODE_P);
  srand(time(NULL));
  double actualTime = SDL_GetTicks();
  double lastTime = actualTime;

  //Initialize Score and Timer
  gManager.initST() ;

  //Load level information from txt
  sManager.load(gManager.getFishs(), gManager.getScore(), gManager.getTimer(), "stages/niveau_"+std::to_string(lvl)+".txt");
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

    resetIManagerBool();

    if (iManager.getUpdate()) {
      iManager.update();
      if(iManager.doReloadLvl()){
        reloadLvl();
      }
      if(iManager.nextLvl()){
        if(lvl < 4){ //Remember to set it to the nr of lvl
          sManager.save(gManager.getScore(), "scores/niveau_"+std::to_string(lvl)+".txt") ;
          lvl++;
          reloadLvl();
        } else {
          // TODO : Find a better way to quit the game
          std::cout << "\t\tCongratulation you've beat all the levels !" << std::endl;
          break;
        }
      }
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

  gManager.destroy();
  iManager.destroy();
}

void Game::reloadLvl(){
  gManager.cleanOld();
  sManager.load(gManager.getFishs(), gManager.getScore(), gManager.getTimer(), "stages/niveau_"+std::to_string(lvl)+".txt");
  gManager.fillFish();
  gManager.setObjectif();
  gManager.sort();
  gManager.getScore()->initScore(s.getRenderer());
  gManager.getTimer()->updateTimer(s.getRenderer());
  resetIManagerBool();
}

void Game::resetIManagerBool(){
  iManager.setPause(i.isActive(SDL_SCANCODE_P));
  iManager.setWin((gManager.getTimer()->getValue() <= 0) && (gManager.getScore()->getGoal() <= gManager.getScore()->getValue()));
  iManager.setLose((gManager.getTimer()->getValue() <= 0) && (gManager.getScore()->getGoal() > gManager.getScore()->getValue()));
  iManager.resetBool();
}
