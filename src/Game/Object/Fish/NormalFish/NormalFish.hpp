#pragma once

#include <stdlib.h>
#include <time.h>
#include <random>

#include <SDL2/SDL.h>
#include <algorithm>
#include "../Fish.hpp"

class NormalFish : public Fish {
  private:
    int valeur;

  public:
    /**
    * Constructor
    */
    NormalFish(Renderer const& r, std::string s, Vector2D<int> coord, float const& z);
    /**
     * Deconstructor
     */
    ~NormalFish();

    float getDir();
    void setDir(float d);
    int getValue();
    void setDegre(float d);
    float getDegre();

};
