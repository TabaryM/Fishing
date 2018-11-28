#pragma once

#include <SDL2/SDL.h>
#include "../Object.hpp"
#include "../../../Stage/Renderer/Renderer.hpp"

class Score : public Text, public Object {
  private:
    int value ;
    int goal ;

  public:
    /**
    * Constructor
    */
    Score(Renderer const& r, Vector2D<int> const& coord, float const& z, Font* f);
    /**
     * Deconstructor
     */
    ~Score();
    int getType() override;
    void addScore(Renderer const& r, int s);
    int getValue();
    int getGoal();
    void setGoal(int g) ;

};
