#pragma once

#include <SDL2/SDL.h>
#include "../../Math/Vector2D.hpp"

class Event {
  private:
    SDL_Event item;

  public:
    Event();
    ~Event();
    int const getType() const;
    SDL_Scancode const getScancode() const;
    Uint8 const getButton() const;
    void poll();
    Vector2D<int> getMousePos();

};
