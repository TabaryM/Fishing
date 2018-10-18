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
#include "Object/Hook/Hook.hpp"
#include "Manager.hpp"

class Game{
  private:
    Stage s;
    Input i;
    GameManager gManager;
    InterfaceManager iManager;

  public:
    Game(Initializer & init);
    ~Game();
    void launch();

};
