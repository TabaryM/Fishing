#pragma once
  #include <cassert>
  #include <SDL2/SDL.h>


class Initializer {

  private:
    bool sdlInit;

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
