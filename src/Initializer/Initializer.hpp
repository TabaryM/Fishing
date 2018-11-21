#pragma once
  #include <cassert>
  #include <SDL2/SDL.h>
  #include <SDL2/SDL_ttf.h>


class Initializer {

  private:
    bool sdlInit;
    bool sdl_ttfInit;

  public:
    /**
     * Constructor
     */
    Initializer();
    /**
     * Deconstructor
     */
    ~Initializer();
    void initializeSDL();
};
