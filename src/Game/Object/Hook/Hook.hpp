#pragma once

#include <SDL2/SDL.h>
#include "../Object.hpp"

class Hook : public Object {
  private:

  public:
    /**
    * Constructor
    */
    Hook(Renderer const& r, Vector2D<int> const& coord, float const& z);
    /**
     * Deconstructor
     */
    ~Hook();
    int getType() override;

};
