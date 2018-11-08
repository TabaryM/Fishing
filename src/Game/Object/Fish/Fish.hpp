#pragma once

#include <stdlib.h>
#include <time.h>

#include <SDL2/SDL.h>
#include <algorithm>
#include "../Object.hpp"

class Fish : public Object {
  private:
    float direction;
    bool hooked;

  public:
    /**
    * Constructor
    */
    Fish(Renderer const& r, Vector2D<int> const& coord, float const& z);
    /**
     * Deconstructor
     */
    ~Fish();

    float getDir();
    void setDir(float d);
    void setHook();
    bool const& isHooked() const ;
    int getType() override;

};
