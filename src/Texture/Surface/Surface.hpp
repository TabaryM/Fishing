#pragma once

#include <cassert>
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Rectangle/Rectangle.hpp"

class Surface {
  private:
    SDL_Surface* item;

  public:
    Surface() = delete;
    Surface(Vector2D<int> const& size, unsigned char const& r, unsigned char const& g, unsigned char const& b, unsigned char const& a);
    Surface(std::string s);
    ~Surface();
    SDL_Surface* getItem();
    Vector2D<int> getSize();
    void fillRGBA(Rectangle const& rect, unsigned char const& r, unsigned char const& g, unsigned char const& b, unsigned char const& a);


  private:
    static const int DEPTH;
};
