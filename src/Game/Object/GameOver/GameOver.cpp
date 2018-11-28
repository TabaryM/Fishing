#include "GameOver.hpp"

GameOver::GameOver(Renderer const& r, Vector2D<int> const& coord, Font* f, std::string s, float const& z) : Text(f, s), Object(r, getSurface(), coord, z, false) {}

GameOver::~GameOver(){
}

int GameOver::getType() {
  return GAMEOVER;
}
