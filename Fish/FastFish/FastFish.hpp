#pragma once

#include <stdlib.h>
#include <time.h>
#include <random>

#include <SDL2/SDL.h>
#include <algorithm>
#include "../Fish.hpp"

class FastFish : public Fish {
  private:
    
    int valeur;
    bool right;
    int speedX;
    int speedY;
    int timeSpeed;
    int timeDir;
    
  public:
    /**
    * Constructor
    */
    FastFish(Renderer const& r, Vector2D<int> coord, float const& z);
    /**
     * Deconstructor
     */
    ~FastFish();

    int getSpeedX();
    void setSpeedX(int dx);
    int getValue();
    void setSpeedY(int dy);
    int getSpeedY();
    void setRight(bool r);
    bool getRight();
    Vector2D<int> Brain(int br, int bd, int px,int py);
    int collision(int br, int bd, int px,int py);
    void speedChange(int time);
    void dirChange(int time,int cas);
    void goUpDown();
};
