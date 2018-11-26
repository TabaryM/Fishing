#include "Score.hpp"

Score::Score(Renderer const& r, Vector2D<int> const& coord, float const& z, Font const& f) : Object(r, new Surface(f), coord, z), value(0) {
  font = f ;
}

Score::~Score(){
}

int Score::getType() {
  return SCORE;
}

void Score::addScore(int s){
  value += s;
  font.setText("Score: "+getValue());
  //refresh surface
}

int Score::getValue(){
  return value;
}

Font Score::getFont() {
  return font ;
}
