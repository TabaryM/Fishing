#include "InterfaceManager.hpp"


InterfaceManager::InterfaceManager(Stage* s, Input* i) : Manager(s, i) {}

void InterfaceManager::create(){
  objets["Pause"] = new Object(s->getRenderer(), new Surface(100, 100, 125, 125, 125, 255), 100, 100, 1);
  Manager::create();
}

void InterfaceManager::update(){
  updatePause();

}

void InterfaceManager::render(){
  Manager::render();
}

void InterfaceManager::destroy(){
}


void InterfaceManager::updatePause(){
  Manager::updatePause();
}
