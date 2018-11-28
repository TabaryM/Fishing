#pragma once

#include <SDL2/SDL.h>
#include "../Object.hpp"

class Score : public Object {
  private:
    int value;
    Font font;

  public:
    /**
    * Constructor
    */
    Score(Renderer const& r, Vector2D<int> const& coord, float const& z);
    /**
     * Deconstructor
     */
    ~Score();
    int getType() override;

    void addScore(int s);
    int getValue();

};
