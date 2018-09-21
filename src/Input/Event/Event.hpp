#pragma once

#include <SDL2/SDL.h>

class Event {
  private:
    SDL_Event item;

  public:
    Event();
    ~Event();
    int const getType() const;
    void poll();

};
