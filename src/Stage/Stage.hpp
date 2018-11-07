#pragma once

#include "Window/Window.hpp"
#include "../Texture/Texture.hpp"
#include "Renderer/Renderer.hpp"
#include "../Game/Object/Object.hpp"

/**
* Mise en place et entretient de la scène d'affichage
*/
class Stage{
  private:
    /**
    * Fenètre d'affichage
    */
    Window w;
    /**
    * Système de Rendu
    */
    Renderer r;
  public:
    /**
     * Constructor
     * @param i use to initialize SDL
     */
    Stage(Initializer & i);
    ~Stage();
    Renderer const& getRenderer() const;
    void clear();
    void draw(Texture & t);
    void draw(int const& x1, int const& y1, int const& x2, int const& y2);
    void draw(Object& o);
    void update();
};
