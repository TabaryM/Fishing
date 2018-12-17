#pragma once

#include "../../../Object/GameOver/GameOver.hpp"

class Bouton : public Object {
  private:
    bool cliquable;
  public:
    Bouton(Renderer const& r, Vector2D<int> const& coord, Surface* s) ;
    ~Bouton();
    bool isHit(Vector2D<int>);
    void setActive(bool a);

    int getType();
};
