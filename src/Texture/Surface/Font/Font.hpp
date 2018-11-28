#pragma once

#include <cassert>
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Font {
  private:
    TTF_Font* font;
    SDL_Color c;
    char const* text;

  public:
    Font();
    ~Font();
    TTF_Font* getFont();
    SDL_Color getColor();
    SDL_Surface* getSurface();
    void setText(char const* c);
};
