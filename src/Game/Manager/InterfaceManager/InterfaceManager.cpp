#include "InterfaceManager.hpp"


InterfaceManager::InterfaceManager(Stage* s, Input* i) : Manager(s, i), pauseActive(true), winActive(false), loseActive(false) {}

void InterfaceManager::create(){
  objets["RetourMenu"] = new Bouton(s->getRenderer(), Vector2D<int>(1, 1), true) ;
  objets["MenuPause"] = new Bouton(s->getRenderer(), Vector2D<int>(Window::WIDTH /2 -305, Window::HEIGHT /2 -75), false) ;
  objets["Pause"] = new Object(s->getRenderer(), new Surface("sprites/Pause.png"), Vector2D<int>(Window::WIDTH /2 -305, Window::HEIGHT /2 -75), 999);
  objets["MenuPause"]->link(objets["Pause"]) ;
  objets["MenuLose"] = new Bouton(s->getRenderer(), Vector2D<int>(Window::WIDTH /2, Window::HEIGHT /2), false) ;
  objets["Lose"] = new GameOver(s->getRenderer(), Vector2D<int>(Window::WIDTH /2 - 138, Window::HEIGHT /3 - 25), &f, std::string("Defaite"), false) ;
  objets["MenuLose"]->link(objets["Lose"]) ;
  objets["MenuWin"] = new Bouton(s->getRenderer(), Vector2D<int>(Window::WIDTH /2, Window::HEIGHT /2), false) ;
  objets["Win"] = new GameOver(s->getRenderer(), Vector2D<int>(Window::WIDTH /2 - 138, Window::HEIGHT /3 - 25), &f, std::string("Victoire !"), false) ;
  objets["MenuWin"]->link(objets["Win"]) ;
  Manager::create();
}

void InterfaceManager::update(){
  objets["MenuLose"]->setActive(loseActive);
  objets["MenuWin"]->setActive(winActive);
  if(winActive || loseActive){
    pauseActive = false;
  }
  objets["MenuPause"]->setActive(pauseActive);
  if(i->isActive(SDL_BUTTON_LEFT)){
    std::cout << "Petite victoire" << std::endl;
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
