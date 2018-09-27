#pragma once

#include <SDL2/SDL.h>
#include "../Object.hpp"

class Fish : public Object {
  private:

  public:
    /**
    * Constructor
    */
    Fish(Renderer const& r, int const& x, int const& y);
    /**
     * Deconstructor
     */
    ~Fish();
    
};

