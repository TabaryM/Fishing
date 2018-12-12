#pragma once

#include <SDL2/SDL.h>
#include "../Object.hpp"

class Hitbox : public Object {
  private:

  public:
    /**
    * Constructor
    */
    Hitbox(Renderer const& r, Vector2D<int> const& coord, float const& z);
    /**
     * Deconstructor
     */
    ~Hitbox();
    int getType() override;
};
