#pragma once

#include "Window/Window.hpp"
#include "../Texture/Texture.hpp"
#include "Renderer/Renderer.hpp"

class Stage{
  private:
    Window w;
    Renderer r;
  public:
    Stage(Initializer & i);
    ~Stage();
    Renderer const& getRenderer() const;
    void clear();
    void draw(Texture & t);
    void update();
};
