#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "../../Texture/Texture.hpp"

class Object {
  private:
    Texture graphic;
    float z;
    std::vector<Object*> child;


  public:
    /**
    * Constructor
    */
    Object(Renderer const& r, Surface* s, int const& x, int const& y, float const& z);
    /**
     * Deconstructor
     */
    ~Object();

    void link(Object* c);
    Texture& getTexture();
    void setZ(float const& v);
    int const& getX() const;
    int const& getY() const;
    float const& getZ() const;
    int const& getW() const;
    int const& getH() const;
    float getDepth() const;
    void move(float const& x, float const& y);
    bool borderCollide(Rectangle const& r);


  public:
    struct ObjectCompare {
      bool operator()(const Object* a, const Object* b) {
        return a->getZ() < b->getZ();
      }
    };
};
