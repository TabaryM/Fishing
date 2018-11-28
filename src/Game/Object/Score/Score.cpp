#include "Score.hpp"

Score::Score(Renderer const& r, Vector2D<int> const& coord, float const& z, Font* f) : Text(f, " "), Object(r, getSurface(), coord, z, false), value(0) {}

Score::~Score(){
}

int Score::getType() {
  return SCORE;
}

void Score::addScore(Renderer const& r, int s){
  value += s;
  update(r, "Score : "+std::to_string(getValue()));
  updateTexture(r, getSurface());
}

int Score::getValue(){
  return value;
}
