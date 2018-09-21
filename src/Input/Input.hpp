#pragma once

#include <SDL2/SDL.h>
#include "Event/Event.hpp"

class Input {
  private:
    bool quit;
    Event e;

  public:
    Input();
    ~Input();
    bool const& isQuit() const;
    void update();

};
