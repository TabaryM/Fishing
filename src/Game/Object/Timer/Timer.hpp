#pragma once

#include <SDL2/SDL.h>
#include "../Object.hpp"

class Timer : public Object {
  private:
    int value;
    int fps;
    Font font;

  public:
    /**
    * Constructor
    */
    Timer(Renderer const& r, Vector2D<int> const& coord, float const& z);
    /**
     * Deconstructor
     */
    ~Timer();
    int getType() override;
    void sec(int s);
    int getValue();

};
