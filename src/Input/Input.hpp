#pragma once

#include <SDL2/SDL.h>
#include "Event/Event.hpp"
#include "Key/Key.hpp"


class Input {
  private:
    bool quit;
    Event e;
    Key* keyKB;
    Key* keyMouse;

  public:
    Input();
    ~Input();
    bool const& isQuit() const;
    void update();
    bool const& isActive(SDL_Scancode const& i);

};
