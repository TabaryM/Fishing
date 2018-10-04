#pragma once

#include <stdlib.h>
#include <time.h>

#include <SDL2/SDL.h>
#include <algorithm>
#include "../Object.hpp"

class Fish : public Object {
  private:
    float direction;

  public:
    /**
    * Constructor
    */
    Fish(Renderer const& r, int const& x, int const& y, float const& z);
    /**
     * Deconstructor
     */
    ~Fish();

    float getDir();
    void setDir(float d);

};
