#include "InterfaceManager.hpp"


InterfaceManager::InterfaceManager(Stage* s, Input* i) : Manager(s, i), pauseActive(true), winActive(false), loseActive(false), nxtLvl(false), reloadLvl(false), quit(false) {}

void InterfaceManager::create(){
  objets["MenuPause"] = new Bouton(s->getRenderer(), Vector2D<int>(Window::WIDTH /2 -305, Window::HEIGHT /2 -75), new Surface(Vector2D<int> (1, 1), 0, 0, 0, 0)) ;
  objets["Pause"] = new Object(s->getRenderer(), new Surface("sprites/Pause.png"), Vector2D<int>(Window::WIDTH /2 -305, Window::HEIGHT /2 -75), 999);
  objets["MenuPause"]->link(objets["Pause"]) ;

  objets["MenuLose"] = new Bouton(s->getRenderer(), Vector2D<int>(Window::WIDTH /2, Window::HEIGHT /2), new Surface(Vector2D<int> (1, 1), 0, 0, 0, 0)) ;
  objets["Lose"] = new GameOver(s->getRenderer(), Vector2D<int>(Window::WIDTH /2 - 138, Window::HEIGHT /3 - 25), &f, std::string("Defaite"), false) ;
  objets["MenuLose"]->link(objets["Lose"]) ;

  objets["MenuWin"] = new Bouton(s->getRenderer(), Vector2D<int>(Window::WIDTH /2, Window::HEIGHT /2), new Surface(Vector2D<int> (1, 1), 0, 0, 0, 0)) ;
  objets["Win"] = new GameOver(s->getRenderer(), Vector2D<int>(Window::WIDTH /2 - 138, Window::HEIGHT /3 - 25), &f, std::string("Victoire !"), false) ;
  objets["MenuWin"]->link(objets["Win"]) ;

  objets["ReloadLvl"] = new Bouton(s->getRenderer(),Vector2D<int>(Window::WIDTH / 3 - 80, Window::HEIGHT * 2 / 3), new Surface("sprites/Reload.png"));
  objets["NextLvl"] = new Bouton(s->getRenderer(), Vector2D<int>(Window::WIDTH / 3 - 80, Window::HEIGHT * 2 / 3), new Surface("sprites/Next.png"));
  objets["MenuWin"]->link(objets["NextLvl"]);
  objets["Quit"] = new Bouton(s->getRenderer(), Vector2D<int>(Window::WIDTH * 2 / 3 - 20, Window::HEIGHT * 2 / 3), new Surface("sprites/Exit.png"));

  Manager::create();
}

void InterfaceManager::update(){
  resetBool();
  static_cast<Bouton*>(objets["MenuLose"])->setActive(loseActive);
  static_cast<Bouton*>(objets["MenuWin"])->setActive(winActive);
  if(winActive || loseActive){
    pauseActive = false;
  }
  static_cast<Bouton*>(objets["MenuPause"])->setActive(pauseActive);
  if(objets["MenuWin"]->isActive()){
    static_cast<Bouton*>(objets["ReloadLvl"])->setActive(false);
  } else {
    static_cast<Bouton*>(objets["ReloadLvl"])->setActive(true);
  }
  if(i->isActive(SDL_BUTTON_LEFT)){
    if(static_cast<Bouton*>(objets["ReloadLvl"])->isHit(i->getMousePos())){
      reloadLvl = true;
    }
    if(static_cast<Bouton*>(objets["NextLvl"])->isHit(i->getMousePos())){
      nxtLvl = true;
    }
    if(static_cast<Bouton*>(objets["Quit"])->isHit(i->getMousePos())){
      quit = true;
    }
  }
}

void InterfaceManager::render(){
  Manager::render();
}

void InterfaceManager::setWin(bool b){
  winActive = b ;
}

void InterfaceManager::setPause(bool b){
  pauseActive = b ;
}

void InterfaceManager::setLose(bool b){
  loseActive = b ;
}

bool InterfaceManager::getUpdate(){
  return (pauseActive || winActive || loseActive);
}

bool InterfaceManager::nextLvl(){
  return nxtLvl;
}

bool InterfaceManager::doReloadLvl(){
  return reloadLvl;
}

bool InterfaceManager::doQuit(){
  return quit;
}

void InterfaceManager::resetBool(){
  reloadLvl = false;
  nxtLvl = false;
  quit = false;
}
