#pragma once

#include <stdlib.h>
#include <time.h>
#include <random>

#include <SDL2/SDL.h>
#include <algorithm>
#include "../Object.hpp"

class Fish : public Object {
  private:
    float direction;
    int right;
    float degre;
    bool hooked;

  public:
    /**
    * Constructor
    */
    Fish(Renderer const& r, Vector2D<int> const& coord, float const& z, int type);
    /**
     * Deconstructor
     */
    ~Fish();

    float getDir();
    void setDir(float d);
    void setRight(int r);
    int getRight();
    void setDegre(float d);
    float getDegre();
    void setHook();
    bool const& isHooked() const ;
    int getType() override;
    void insert(Fish f);
    std::string getSprite(int type) ;

};
