#pragma once

#include <stdlib.h>
#include <time.h>
#include <random>

#include <SDL2/SDL.h>
#include <algorithm>
#include "../Object.hpp"

class Fish : public Object {
  private:
    float direction;
    int right;

  public:
    /**
    * Constructor
    */
    Fish(Renderer const& r, std::string s, int const& x, int const& y, float const& z);
    /**
     * Deconstructor
     */
    ~Fish();

    float getDir();
    void setDir(float d);

};
