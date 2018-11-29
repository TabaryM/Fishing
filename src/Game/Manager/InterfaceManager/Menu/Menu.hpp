#pragma once

#include "../../../Object/GameOver/GameOver.hpp"

class Menu : public Object {
  public:
    Menu(Renderer const& r, Vector2D<int> const& coord) ;
    ~Menu();
};
