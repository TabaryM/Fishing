#include "Score.hpp"

Score::Score(Renderer const& r, Vector2D<int> const& coord, float const& z) : Object(r, new Surface(new Font()),coord, z), value(0), font() {
  //super(r, new Surface(TTF_RenderText_Solid(font.getFont(),"Hello World!", font.getColor())),coord, z);
  //TTF_RenderText_Solid(font.getFont(),"Hello World!", font.getColor())
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
