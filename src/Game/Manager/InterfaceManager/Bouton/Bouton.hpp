#pragma once

#include "../../../Object/GameOver/GameOver.hpp"

class Bouton : public Object {
  public:
    Bouton(Renderer const& r, Vector2D<int> const& coord, Surface* s) ;
    ~Bouton();
    bool isHit(Vector2D<int>);

    int getType();
};
