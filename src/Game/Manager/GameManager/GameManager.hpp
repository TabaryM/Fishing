#pragma once

#include "Object/Object.hpp"
#include "Object/Fish/Fish.hpp"
#include "Object/Boat/Boat.hpp"
#include "Object/Hook/Hook.hpp"

class GameManager : public Manager {

  private:
  std::map<std::string, Object*> objets;
  std::vector<Object*> draws;
  int speed;
  Rectangle borders;

  public:
  GameManager(Stage* s);
  GameManager::~GameManager();

}
