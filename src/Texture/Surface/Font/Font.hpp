#pragma once

#include <cassert>
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Font {
  private:
    TTF_Font* font;

  public:
    Font();
    ~Font();
    TTF_Font& getFont() const;
};
