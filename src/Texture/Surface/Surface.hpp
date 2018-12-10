#pragma once

#include <cassert>
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Rectangle/Rectangle.hpp"
#include "Font/Font.hpp"

class Surface {
  private:
    SDL_Surface* item;
    int alpha = 255;

  public:
    Surface() = delete;
    Surface(Vector2D<int> const& size, unsigned char const& r, unsigned char const& g, unsigned char const& b, unsigned char const& a);
    Surface(std::string s);
    Surface(Font* f, std::string const& str);
    ~Surface();
    void loadText(Font* f, std::string const& str);
    SDL_Surface* getItem();
    Vector2D<int> getSize();
    void fillRGBA(Rectangle const& rect, unsigned char const& r, unsigned char const& g, unsigned char const& b, unsigned char const& a);
    void free();
    int getAlpha();

  private:
    static const int DEPTH;
};
