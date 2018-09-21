#pragma once

#include <iostream>
#include "../Stage/Stage.hpp"
#include "../Input/Input.hpp"

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
