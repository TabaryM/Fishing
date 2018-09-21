#pragma once

#include <cassert>
#include <SDL2/SDL.h>

#include "../Window/Window.hpp"
#include "../../Texture/Surface/Surface.hpp"

class Texture;

class Renderer {
  private:
    SDL_Renderer* item;

  public:
    Renderer(Window const& w);
    ~Renderer();
    SDL_Texture* getTexture(Surface* s) const;
    void draw(Texture & t);
    void clear();
    void update();
};
