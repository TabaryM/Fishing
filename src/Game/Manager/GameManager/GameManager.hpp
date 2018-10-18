#pragma once

#include "../../Object/Object.hpp"
#include "../../Object/Fish/Fish.hpp"
#include "../../Object/Boat/Boat.hpp"
#include "../../Object/Hook/Hook.hpp"
#include "../Manager.hpp"

class GameManager : public Manager {

  public:
  GameManager(Stage* s, Input* i);
  ~GameManager();

};
