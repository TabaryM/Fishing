#pragma once

#include <SDL2/SDL.h>
#include "../../Texture/Texture.hpp"

class Object {
  private:
    Texture graphic;


  public:
    /**
    * Constructor
    */
    Object(Renderer const& r, Surface* s, int const& x, int const& y);
    /**
     * Deconstructor
     */
    ~Object();

    Texture& getTexture();
    void setX(int const& x);
    void setY(int const& y);
};
