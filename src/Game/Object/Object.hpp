#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <functional>
#include "../../Texture/Texture.hpp"

enum ObjectType {
  OBJECT,
  FISH,
  HOOK,
  BOAT,
  SCORE,
  TIMER,
  GAMEOVER,
  HITBOX
};

class Object {
  private:
    Texture graphic;
    float z;
    std::vector<Object*> child;
    bool flip;
    bool active;

  public:
    /**
    * Constructor
    */
    Object(Renderer const& r, Surface* s, Vector2D<int> const& coord, float const& z, bool destroyOnload = true);
    /**
     * Deconstructor
     */
    virtual ~Object();

    void link(Object* c);
    Texture& getTexture();
    void setZ(float const& v);
    Vector2D<int> const& getCoord() const;
    Vector2D<int> const& getSize() const;
    int const& getX() const;
    int const& getY() const;
    int const& getW() const;
    int const& getH() const;
    float const& getZ() const;
    float getDepth() const;
    void move(Vector2D<int> const& dep);
    void collide(std::function<void(Object*, Object*)> callback, Object* o);
    virtual int getType();
    std::vector<Object*>&  getChild();
    void updateTexture(Renderer const& r, Surface* s);

    void flipingTo(bool a);
    bool const& isFliped() const ;
    void isFlip();
    virtual Vector2D<int>* getCorner();
    virtual Rectangle getHitbox();

  public:
    struct ObjectCompare {
      bool operator()(const Object* a, const Object* b) {
        return a->getZ() < b->getZ();
      }
    };
};
