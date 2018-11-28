#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <cassert>

class Font {
  private:
    TTF_Font* font;
    SDL_Color c;

  public:
    Font();
    ~Font();
    TTF_Font* getFont();
    SDL_Color getColor();
};
