#include "InterfaceManager.hpp"


InterfaceManager::InterfaceManager(Stage* s, Input* i) : Manager(s, i), pauseActive(true), winActive(false), loseActive(false) {}

void InterfaceManager::create(){
  objets["MenuPause"] = new Menu(s->getRenderer(), Vector2D<int>(Window::WIDTH /2 -305, Window::HEIGHT /2 -75)) ;
  objets["Pause"] = new Object(s->getRenderer(), new Surface("sprites/Pause.png"), Vector2D<int>(Window::WIDTH /2 -305, Window::HEIGHT /2 -75), 999);
  objets["MenuPause"]->link(objets["Pause"]) ;
  objets["MenuLose"] = new Menu(s->getRenderer(), Vector2D<int>(Window::WIDTH /2, Window::HEIGHT /2)) ;
  objets["Lose"] = new GameOver(s->getRenderer(), Vector2D<int>(Window::WIDTH /2 - 138, Window::HEIGHT /2 - 25), &f, std::string("Defaite")) ;
  objets["MenuLose"]->link(objets["Lose"]) ;
  objets["MenuWin"] = new Menu(s->getRenderer(), Vector2D<int>(Window::WIDTH /2, Window::HEIGHT /2)) ;
  objets["Win"] = new GameOver(s->getRenderer(), Vector2D<int>(Window::WIDTH /2 - 138, Window::HEIGHT /2 - 25), &f, std::string("Victoire !")) ;
  objets["MenuWin"]->link(objets["Win"]) ;
  Manager::create();
}

void InterfaceManager::update(){
  objets["MenuLose"]->setActive(loseActive);
  objets["MenuWin"]->setActive(winActive);
  objets["MenuPause"]->setActive(pauseActive);
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
