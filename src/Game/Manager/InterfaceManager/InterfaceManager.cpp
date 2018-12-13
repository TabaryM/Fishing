#include "InterfaceManager.hpp"


InterfaceManager::InterfaceManager(Stage* s, Input* i) : Manager(s, i), pauseActive(true), winActive(false), loseActive(false), nxtLvl(0), reload(false) {}

void InterfaceManager::create(){
  objets["RetourMenu"] = new Bouton(s->getRenderer(), Vector2D<int>(Window::WIDTH / 3, Window::HEIGHT * 2 / 3), new Surface(Vector2D<int> (100, 100), 100, 100, 100, 100)) ;
  objets["MenuPause"] = new Bouton(s->getRenderer(), Vector2D<int>(Window::WIDTH /2 -305, Window::HEIGHT /2 -75), new Surface(Vector2D<int> (100, 100), 100, 100, 100, 100)) ;
  objets["Pause"] = new Object(s->getRenderer(), new Surface("sprites/Pause.png"), Vector2D<int>(Window::WIDTH /2 -305, Window::HEIGHT /2 -75), 999);
  objets["MenuPause"]->link(objets["Pause"]) ;
  objets["MenuLose"] = new Bouton(s->getRenderer(), Vector2D<int>(Window::WIDTH /2, Window::HEIGHT /2), new Surface(Vector2D<int> (100, 100), 100, 100, 100, 255)) ;
  objets["Lose"] = new GameOver(s->getRenderer(), Vector2D<int>(Window::WIDTH /2 - 138, Window::HEIGHT /3 - 25), &f, std::string("Defaite"), false) ;
  objets["MenuLose"]->link(objets["Lose"]) ;
  objets["MenuWin"] = new Bouton(s->getRenderer(), Vector2D<int>(Window::WIDTH /2, Window::HEIGHT /2), new Surface(Vector2D<int> (200, 200), 100, 100, 100, 100)) ;
  objets["Win"] = new GameOver(s->getRenderer(), Vector2D<int>(Window::WIDTH /2 - 138, Window::HEIGHT /3 - 25), &f, std::string("Victoire !"), false) ;
  objets["MenuWin"]->link(objets["Win"]) ;
  objets["Reset"] = new Bouton(s->getRenderer(),Vector2D<int>(Window::WIDTH / 3, Window::HEIGHT * 2 / 3), new Surface("sprites/Reload.png"));
  Manager::create();
}

void InterfaceManager::update(){
  reload = false;
  objets["MenuLose"]->setActive(loseActive);
  objets["MenuWin"]->setActive(winActive);
  if(winActive || loseActive){
    pauseActive = false;
  }
  objets["MenuPause"]->setActive(pauseActive);
  if(i->isActive(SDL_BUTTON_LEFT)){
    if(static_cast<Bouton*>(objets["Reset"])->isHit(i->getMousePos())){
      reload = true;
    }
  }
}

void InterfaceManager::render(){
  Manager::render();
}

void InterfaceManager::destroy(){}

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

int InterfaceManager::changeLvl(){
  return nxtLvl;
}

bool InterfaceManager::doReload(){
  return reload;
}
