#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>

#include "../Stage/Stage.hpp"
#include "../Input/Input.hpp"
#include "Object/Object.hpp"
#include "Object/Fish/Fish.hpp"
#include "Object/Boat/Boat.hpp"

class Game{
  private:
    Stage s;
    Input i;
    bool again;
    std::map<std::string, Object*> objets;
    std::vector<Object*> draws;
    int speed;

  public:
    Game(Initializer & i);
    ~Game();
    void mainLoop();
    void updateControl(Object* obj);
    void sortObject();

};
