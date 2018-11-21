#include "Score.hpp"

Score::Score(Renderer const& r, Vector2D<int> const& coord, float const& z) : value(0), font(new Font()) {
  Object(r, new Surface(TTF_RenderText_Solid(font,"Hello World!")),coord, z);
}

Score::~Score(){
}

int Score::getType() {
  return SCORE;
}

void Score::addScore(int s){
  value += s;
}

int Score::getScore(){
  return value;
}
