#pragma once

#include <SDL2/SDL.h>
#include "../../Texture/Texture.hpp"

class Object {
  private:
    Texture graphic;
    int z;


  public:
    /**
    * Constructor
    */
    Object(Renderer const& r, Surface* s, int const& x, int const& y, int const& z);
    /**
     * Deconstructor
     */
    ~Object();

    Texture& getTexture();
    void setX(int const& x);
    void setY(int const& y);
    int const& getX() const;
    int const& getY() const;
    int const& getZ() const;
    int const& getW() const;
    int const& getH() const;

  public:
    struct ObjectCompare {
      bool operator()(const Object* a, const Object* b) {
        return a->getZ() < b->getZ();
      }
    };
};
