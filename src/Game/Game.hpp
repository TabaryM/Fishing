#pragma once

#include <iostream>
#include "../Stage/Stage.hpp"
#include "../Input/Input.hpp"
#include "Object/Object.hpp"
#include "Object/Fish/Fish.hpp"

class Game{
  private:
    Stage s;
    Input i;
    bool again;

  public:
    Game(Initializer & i);
    ~Game();
    void mainLoop();

};
