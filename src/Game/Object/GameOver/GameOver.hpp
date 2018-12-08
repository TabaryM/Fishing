#pragma once

#include "../Object.hpp"
#include "../../../Stage/Renderer/Renderer.hpp"


class GameOver : public Text, public Object {

  public:
    /**
    * Constructor
    */
    GameOver(Renderer const& r, Vector2D<int> const& coord, Font* f, std::string s, float const& z = 999, bool destroyOnload = false);
    /**
     * Deconstructor
     */
    ~GameOver();
    int getType() override;
};
