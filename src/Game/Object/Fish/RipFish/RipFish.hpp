#pragma once

#include <stdlib.h>
#include <time.h>
#include <random>

#include <SDL2/SDL.h>
#include <algorithm>
#include "../Fish.hpp"

class RipFish : public Fish {
  private:
    int valeur;

  public:
    /**
    * Constructor
    */
    RipFish(Renderer const& r, int const& x, int const& y, float const& z);
    /**
     * Deconstructor
     */
    ~RipFish();

    float getDir();
    void setDir(float d);
    int getValue();
    
};
