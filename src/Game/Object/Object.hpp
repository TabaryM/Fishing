#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <functional>
#include "../../Texture/Texture.hpp"

enum ObjectType {
  OBJECT,
  FISH,
  HOOK,
  BOAT
};

class Object {
  private:
    Texture graphic;
    float z;
    std::vector<Object*> child;


  public:
    /**
    * Constructor
    */
    Object(Renderer const& r, Surface* s, Vector2D<int> const& coord, float const& z);
    /**
     * Deconstructor
     */
    virtual ~Object();

    void link(Object* c);
    Texture& getTexture();
    void setZ(float const& v);
    Vector2D<int> const& getCoord() const;
    int const& getX() const;
    int const& getY() const;
    int const& getW() const;
    int const& getH() const;
    Vector2D<int> const& getSize() const;
    float const& getZ() const;
    float getDepth() const;
    void move(Vector2D<int> const& dep);
    void collide(std::function<void(Object*, Object*)> callback, Object* o);
    virtual int getType();
    std::vector<Object*>&  getChild();


  public:
    struct ObjectCompare {
      bool operator()(const Object* a, const Object* b) {
        return a->getZ() < b->getZ();
      }
    };
};
