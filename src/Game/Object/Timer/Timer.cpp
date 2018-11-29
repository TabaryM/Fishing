#include "Timer.hpp"

Timer::Timer(Renderer const& r, Vector2D<int> const& coord, float const& z, Font* f) : Text(f, " "), Object(r, getSurface() ,coord, z, false), value(60), fps(0) {}

Timer::~Timer(){
}

int Timer::getType() {
  return TIMER;
}

void Timer::sec(Renderer const& r, int s){
  fps ++;
  if(fps == 60){
    value += s;
    fps = 0;
    updateTimer(r);
  }
}

int Timer::getValue(){
  return value;
}

void Timer::setValue(int v){
  value = v;
}

void Timer::updateTimer(Renderer const& r) {
  update(r, "Time left : "+std::to_string(getValue())+" s");
  updateTexture(r, getSurface());
}
