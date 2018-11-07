#pragma once

#include <SDL2/SDL.h>
#include "../Object.hpp"

class Hook : public Object {
  private:

  public:
    /**
    * Constructor
    */
    Hook(Renderer const& r, int const& x, int const& y, float const& z);
    /**
     * Deconstructor
     */
    ~Hook();

};
