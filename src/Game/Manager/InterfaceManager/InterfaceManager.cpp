#include "InterfaceManager.hpp"


InterfaceManager::InterfaceManager(Stage* s, Input* i) : Manager(s, i) {}

void InterfaceManager::create(){
  Manager::create();
}

void InterfaceManager::update(){
}

void InterfaceManager::render(){
  Manager::render();
}

void InterfaceManager::destroy(){
}
