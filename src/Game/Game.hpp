#pragma once

#include <iostream>
#include <vector>
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
    std::vector<Object*> objets;

  public:
    Game(Initializer & i);
    ~Game();
    void mainLoop();
    void updateControl();

};
