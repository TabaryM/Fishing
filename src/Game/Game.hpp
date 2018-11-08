#pragma once

#include <iostream>

#include "../Stage/Stage.hpp"
#include "../Input/Input.hpp"
#include "Manager/GameManager/GameManager.hpp"
#include "Manager/InterfaceManager/InterfaceManager.hpp"
#include "Manager/SaveManager/SaveManager.hpp"

class Game{
  private:
    Stage s;
    Input i;
    GameManager gManager;
    InterfaceManager iManager;
    SaveManager sManager;

  public:
    Game(Initializer & init);
    ~Game() = default ;
    void launch();

};
