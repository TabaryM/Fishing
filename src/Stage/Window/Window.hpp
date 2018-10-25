#pragma once

#include <SDL2/SDL.h>
#include "../../Initializer/Initializer.hpp"

class Window {

  private:
    SDL_Window* item;

  public:
    /**
     * Constructor
     * @param i use to initialize SDL
     */
    Window(Initializer & i);
    /**
     * Deconstructor
     */
    ~Window();
    SDL_Renderer* getRenderer(int const& index, int const& flags) const;

    static int WIDTH;
    static int HEIGHT;
};
