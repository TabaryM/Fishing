#pragma once

#include <SDL2/SDL.h>
#include "Surface/Surface.hpp"
#include "Surface/Text/Text.hpp"

class Renderer;

class Texture {
  private:
    SDL_Texture* item;
    Rectangle position;

  public:
    /**
    * Constructor
    */
    Texture(Renderer const& r, Surface* s, Vector2D<int> const& coords, bool destroyOnload = true);
    /**
     * Deconstructor
     */
    ~Texture();
    /**
    *Create a texture with an item
    */
    SDL_Texture* getItem();
    Rectangle const& getPosition() const;
    Vector2D<int> const& getCoord() const;
    void setCoord(Vector2D<int> const& coord);
    void update(Renderer const& r, Surface* s);
    void free();

};
