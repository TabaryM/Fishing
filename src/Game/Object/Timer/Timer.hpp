#pragma once

#include <SDL2/SDL.h>
#include "../Object.hpp"
#include "../../../Stage/Renderer/Renderer.hpp"

class Timer : public Text, public Object {
  private:
    int value;
    int fps;

  public:
    /**
    * Constructor
    */
    Timer(Renderer const& r, Vector2D<int> const& coord, float const& z, Font* f);
    /**
     * Deconstructor
     */
    ~Timer();
    int getType() override;
    void sec(Renderer const&r, int s);
    int getValue();
    void setValue(int v);
};
