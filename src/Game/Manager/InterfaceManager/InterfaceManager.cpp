#include "InterfaceManager.hpp"


InterfaceManager::InterfaceManager(Stage* s, Input* i, Font* f) : Manager(s, i, f) {}

void InterfaceManager::create(){
  objets["Pause"] = new Object(s->getRenderer(), new Surface("sprites/Pause.png"), Vector2D<int>(Window::WIDTH /2 -305, Window::HEIGHT /2 -75), 999);
  Manager::create();
}

void InterfaceManager::update(){
}

void InterfaceManager::render(){
  Manager::render();
}

void InterfaceManager::destroy(){
}
