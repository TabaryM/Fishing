#pragma once

#include <SDL2/SDL.h>
#include "../Object.hpp"

class Boat : public Object {
  private:

  public:
    /**
    * Constructor
    */
    Boat(Renderer const& r, int const& x, int const& y, int const& z);
    /**
     * Deconstructor
     */
    ~Boat();

};
