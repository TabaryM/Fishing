#pragma once

#include <stdlib.h>
#include <time.h>
#include <random>

#include <SDL2/SDL.h>
#include <algorithm>
#include "../Fish.hpp"

class NormalFish : public Fish {
  private:
    
    int valeur;
    bool right;
    int speedX;
    int speedY;
    int timeDir;

  public:
    /**
    * Constructor
    */
    NormalFish(Renderer const& r, Vector2D<int> coord, float const& z);
    /**
     * Deconstructor
     */
    ~NormalFish();

    int getSpeedX();
    void setSpeedX(int dx);
    int getValue();
    void setSpeedY(int dy);
    int getSpeedY();
    void setRight(bool r);
    bool getRight();
    void Brain(int br, int bd, int px,int py);
    int collision(int br, int bd, int px,int py);
    void dirChange(int time,int cas);
    void goUpDown();

};
