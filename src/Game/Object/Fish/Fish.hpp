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
    float degre;

  public:
    /**
    * Constructor
    */
    Fish(Renderer const& r, std::string sprite, Vector2D<int> const& coord, float const& z);
    /**
     * Deconstructor
     */
    ~Fish();

    float getDir();
    void setDir(float d);
    void setRight(int r);
    int getRight();
    void setDegre(float d);
    float getDegre();
    int getType() override;

};
