#include "Score.hpp"

Score::Score(Renderer const& r, Vector2D<int> const& coord, float const& z) : Object(r, new Surface(new Font()),coord, z), value(0), font() {
}

Score::~Score(){
}

int Score::getType() {
  return SCORE;
}

void Score::addScore(int s){
  value += s;
  font.setText("Score: "+getScore());
  //refresh surface
}

int Score::getScore(){
  return value;
}
