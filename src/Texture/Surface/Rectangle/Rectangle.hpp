#pragma once

#include <SDL2/SDL.h>
#include "../../../Math/Vector2D.hpp"

class Rectangle {
  private:
    Vector2D<int> size;
    Vector2D<int> coord;

  public:
    Rectangle() = default;
    Rectangle(Vector2D<int> const& size, Vector2D<int> const& coord = Vector2D<int>());
    ~Rectangle() = default;
    Vector2D<int> const& getCoord() const;
    Vector2D<int> const& getSize() const;
    int const& getH() const;
    int const& getW() const;
    void setCoord(Vector2D<int> const& coord);
    SDL_Rect getRect() const;

};
