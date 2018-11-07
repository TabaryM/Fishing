#pragma once

#include <stdlib.h>
#include <time.h>
#include <random>

#include <SDL2/SDL.h>
#include <algorithm>
#include "../Fish.hpp"

class GoldFish : public Fish {
  private:
    int valeur;

  public:
    /**
    * Constructor
    */
    GoldFish(Renderer const& r, Vector2D<int> coord, float const& z);
    /**
     * Deconstructor
     */
    ~GoldFish();

    float getDir();
    void setDir(float d);
    int getValue();
    void setDegre(float d);
    float getDegre();

};
