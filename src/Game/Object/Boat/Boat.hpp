#pragma once

#include <SDL2/SDL.h>
#include "../Object.hpp"

class Boat : public Object {
  private:

  public:
    /**
    * Constructor
    */
    Boat(Renderer const& r, Vector2D<int> const& coord, float const& z);
    /**
     * Deconstructor
     */
    ~Boat();
    int getType() override;

};
