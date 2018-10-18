#include "InterfaceManager.hpp"


InterfaceManager::InterfaceManager(Stage* s, Input* i) : Manager(s, i) {}

InterfaceManager::~InterfaceManager(){
}

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
