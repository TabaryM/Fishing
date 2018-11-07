#pragma once

#include <SDL2/SDL.h>
#include "../Object.hpp"

class Wave : public Object {
  private:

  public:
    /**
    * Constructor
    */
    Wave(Renderer const& r, Vector2D<int> const& coord, float const& z);
    /**
     * Deconstructor
     */
    ~Wave();

};
