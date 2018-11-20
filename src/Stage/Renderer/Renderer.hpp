#pragma once

#include <cassert>
#include <SDL2/SDL.h>

#include "../Window/Window.hpp"
#include "../../Texture/Surface/Surface.hpp"
#include "../../Texture/Texture.hpp"

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
     * Draw the texture
     * @param t with the SDL Library
     */
    void draw(Texture & t);
    /**
     * Draw the line
     * @param x1, x2, y1, y2
     */
    void draw(int const& x1, int const& y1, int const& x2, int const& y2);
    /**
      * Flip the texture
      * @param t the texture
      */
    void flip(Texture& t);
    /**
     * Clear the stage
     */
    void clear();
    /**
     * update the stage
     */
    void update();
};
