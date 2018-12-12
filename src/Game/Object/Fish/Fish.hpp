#pragma once

#include <stdlib.h>
#include <time.h>
#include <random>

#include <SDL2/SDL.h>
#include <algorithm>
#include "../Object.hpp"
#include "../Score/Score.hpp"
#include "../Hitbox/Hitbox.hpp"

class Fish : public Object {
  private:
    bool right;
    int speedX;
    int speedY;
    bool hooked;
    int typeFish;
    int timeDir;
    int timeSpeed;
    int timeupdown;
    Hitbox* hitbox;

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
    void setSpeedX(int dx);
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
    void getPoints(Renderer const& r, Score* s) ;
    int getPoints();

    Vector2D<int>* getCorner() override;
    Rectangle getHitbox() override;
    
    Vector2D<int> Brain(int br, int bd, int hx, int hy, int hw, int hh);
    int collision(int br, int bd, int hx, int hy, int hw, int hh);
    void dirChange(int time,int cas);
    void speedChange(int time);
    void upDownChange(int time);
    void goUpDown();

};
