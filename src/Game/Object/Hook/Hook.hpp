#pragma once

#include <SDL2/SDL.h>
#include "../Object.hpp"
#include "../Hitbox/Hitbox.hpp"

class Hook : public Object {
  private:
    Hitbox* hitbox;
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
    Rectangle getHitbox() override;
};
