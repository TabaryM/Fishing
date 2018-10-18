#pragma once

#include "../Stage/Stage.hpp"
#include "../Input/Input.hpp"

class Manager {
  public:
    Stage* s;
    Input* i;

  public:
    Manager();
    ~Manager();

}
