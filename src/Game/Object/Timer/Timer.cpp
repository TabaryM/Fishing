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
    //std::cout << "(modif)value : " << value << std::endl;
    value += s;
    fps = 0;
    updateTimer(r);
  }
}

int Timer::getValue(){
  return value;
}

void Timer::setValue(int v){
  std::cout << "value : " << value << "\nv : " << v << std::endl;
  value = v;
  std::cout << "value : " << value << std::endl;
}

void Timer::updateTimer(Renderer const& r) {
  update(r, "Time left : "+std::to_string(getValue())+" s");
  updateTexture(r, getSurface());
}
