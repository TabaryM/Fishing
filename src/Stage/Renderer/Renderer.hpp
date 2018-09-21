#pragma once

#include <cassert>
#include <SDL2/SDL.h>

#include "../Window/Window.hpp"
#include "../../Texture/Surface/Surface.hpp"

class Texture;

class Renderer {
  private:
    SDL_Renderer* item;

  public:
    /**
     * Constructor
     * @param w use to initialize the Window
     */
    Renderer(Window const& w);
    /**
     * Deconstructor
     */
    ~Renderer();
    /**
     * Getter
     * @param s use to know what surface is used
     */
    SDL_Texture* getTexture(Surface* s) const;
    /**
     * Draw the texture t with the SDL Library
     */
    void draw(Texture & t);
    /**
     * Clear the stage
     */
    void clear();
    /**
     * update the stage
     */
    void update();
};
