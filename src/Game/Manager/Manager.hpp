#pragma once

#include "../../Stage/Stage.hpp"
#include "../../Input/Input.hpp"

class Manager {
  protected:
    Stage* s;
    Input* i;

  public:
    Manager(Stage* s, Input* i);
    ~Manager();

};
