#pragma once

#include "Object/Object.hpp"
#include "Object/Fish/Fish.hpp"
#include "Object/Boat/Boat.hpp"
#include "Object/Hook/Hook.hpp"

class InterfaceManager : public Manager {

  private:
  std::map<std::string, Object*> objets;
  std::vector<Object*> draws;
  int speed;
  Rectangle borders;

  public:
  InterfaceManager(Stage* s);
  InterfaceManager::~InterfaceManager();

}
