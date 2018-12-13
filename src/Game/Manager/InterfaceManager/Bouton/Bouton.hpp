#pragma once

#include "../../../Object/GameOver/GameOver.hpp"

class Bouton : public Object {
  private:
    bool cliquable ;
  public:
    Bouton(Renderer const& r, Vector2D<int> const& coord, bool cliquable) ;
    ~Bouton();
    bool isHit(Vector2D<int>);

    int getType();
};
