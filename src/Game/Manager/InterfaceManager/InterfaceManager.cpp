#include "InterfaceManager.hpp"


InterfaceManager::InterfaceManager(Stage* s, Input* i) : Manager(s, i) {}

void InterfaceManager::create(){
  objets["Pause"] = new Object(s->getRenderer(), new Surface("sprites/Pause.png"), Vector2D<int>(Window::WIDTH /2 -305, Window::HEIGHT /2 -75), 999);
  //objets["GO"] = new Object
  Manager::create();
}

void InterfaceManager::update(){
  if(!SDL_SCANCODE_P){

  }
}

void InterfaceManager::render(){
  Manager::render();
}

void InterfaceManager::destroy(){
}
