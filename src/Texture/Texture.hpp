#pragma once

#include <SDL2/SDL.h>
#include "Surface/Rectangle/Rectangle.hpp"
#include "Surface/Surface.hpp"

class Renderer;

class Texture {
  private:
    SDL_Texture* item;
    Rectangle position;

  public:
    Texture(Renderer const& r, Surface* s, int const& x, int const& y);
    ~Texture();
    SDL_Texture* getItem();
    Rectangle const& getPosition() const ;

};
