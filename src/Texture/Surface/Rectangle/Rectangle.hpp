#pragma once

#include <SDL2/SDL.h>

class Rectangle {
  private:
    SDL_Rect item;

  public:
    Rectangle();
    Rectangle(int const& w, int const& h, int const& x = 0, int const& y = 0);
    ~Rectangle();
    int const& getX() const;
    int const& getY() const;
    int const& getW() const;
    int const& getH() const;
    void setX(int const& x);
    void setY(int const& y);
    SDL_Rect const& getItem() const;

};
