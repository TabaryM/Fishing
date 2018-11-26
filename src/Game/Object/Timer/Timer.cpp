#include "Timer.hpp"

Timer::Timer(Renderer const& r, Vector2D<int> const& coord, float const& z) : Object(r, new Surface(new Font()),coord, z), value(10), font() {
  fps = 0;
}

Timer::~Timer(){
}

int Timer::getType() {
  return TIMER;
}

void Timer::sec(int s){
  fps ++;
  if(fps == 60){
    value += s;
    font.setText(getValue()+"");
    fps = 0;
  }
  //refresh surface
}

int Timer::getValue(){
  return value;
}
