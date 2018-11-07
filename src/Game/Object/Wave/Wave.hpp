#pragma once

#include <SDL2/SDL.h>
#include "../Object.hpp"

class Wave : public Object {
  private:

  public:
    /**
    * Constructor
    */
    Wave(Renderer const& r, int const& x, int const& y, float const& z);
    /**
     * Deconstructor
     */
    ~Wave();

};
