#pragma once

#include <stdlib.h>
#include <time.h>
#include <random>

#include <SDL2/SDL.h>
#include <algorithm>
#include "../Fish.hpp"

class BombFish : public Fish {
  private:
    int valeur;

  public:
    /**
    * Constructor
    */
    BombFish(Renderer const& r,  Vector2D<int> coord, float const& z) ;
    /**
     * Deconstructor
     */
    ~BombFish();

    float getDir();
    void setDir(float d);
    int getValue();
    void setDegre(float d);
    float getDegre();

};
