#include "InterfaceManager.hpp"


InterfaceManager::InterfaceManager(Stage* s, Input* i) : Manager(s, i) {}

void InterfaceManager::create(){
  objets["MenuPause"] = new Menu(s->getRenderer(), Vector2D<int>(Window::WIDTH /2 -305, Window::HEIGHT /2 -75)) ;
  objets["Pause"] = new Object(s->getRenderer(), new Surface("sprites/Pause.png"), Vector2D<int>(Window::WIDTH /2 -305, Window::HEIGHT /2 -75), 999);
  objets["MenuPause"]->link(objets["Pause"]) ;
  //objets["Win"] = new GameOver(s->getRenderer(), Vector2D<int>(Window::WIDTH /2 -305, Window::HEIGHT /2 -75), &f, std::string("Victoire !")) ;
  //objets["Lose"] = new GameOver(s->getRenderer(), Vector2D<int>(Window::WIDTH /2 -305, Window::HEIGHT /2 -75), &f, std::string("Defaite")) ;
  //objets["GO"] = new Object
  Manager::create();
}

void InterfaceManager::update(){
  /*
  if(!SDL_SCANCODE_P){
    objets["Pause"]->setZ(-1.0) ;
  }else{
    objets["Win"]->setZ(-1.0) ;
    objets["Lose"]->setZ(-1.0) ;
  }
  */
}

void InterfaceManager::render(){
  Manager::render();
}

void InterfaceManager::destroy(){
}
