#pragma once

#include <SDL2/SDL.h>
#include <algorithm>
#include "../Object.hpp"

class Fish : public Object {
  private:

  public:
    /**
    * Constructor
    */
    Fish(Renderer const& r, int const& x, int const& y, float const& z);
    /**
     * Deconstructor
     */
    ~Fish();

};
