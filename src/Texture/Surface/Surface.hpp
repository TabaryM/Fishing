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
    Surface(int const& w, int const& h, unsigned char const& r, unsigned char const& g, unsigned char const& b, unsigned char const& a);
    Surface(std::string s);
    ~Surface();
    SDL_Surface* getItem();
    int const& getW() const;
    int const& getH() const;
    void fillRGBA(Rectangle const& rect, unsigned char const& r, unsigned char const& g, unsigned char const& b, unsigned char const& a);


  private:
    static const int DEPTH;
};
