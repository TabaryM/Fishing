#pragma once

#include <stdlib.h>
#include <time.h>
#include <random>

#include <SDL2/SDL.h>
#include <algorithm>
#include "../Object.hpp"

class Fish : public Object {
  private:
    bool right;
    int speedX;
    int speedY;
    bool hooked;
    int typeFish;
    
  public:
    /**
    * Constructor
    */
    Fish(Renderer const& r, Vector2D<int> const& coord, float const& z, int typeFish);
    /**
     * Deconstructor
     */
    ~Fish();

    int getSpeedX();
    void setRight(bool r);
    bool getRight();
    void setSpeedY(int d);
    int getSpeedY();
    void setHook();
    bool const& isHooked() const ;
    int getType() override;
    void insert(Fish f);
    std::string getSprite(int type) ;
    int getTypeFish() ;

};
