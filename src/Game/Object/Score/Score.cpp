#include "Score.hpp"

Score::Score(Renderer const& r, Vector2D<int> const& coord, float const& z) : Object(r, new Surface("sprites/Kappa.png"/*TODO: insert text here*/), coord, z), score(0) {}

Score::~Score(){
}

int Score::getType() {
  return SCORE;
}

void Score::addScore(int s){
  score += s;
}

int Score::getScore(){
  return score;
}
