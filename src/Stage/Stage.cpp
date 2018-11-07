#include "Stage.hpp"

Stage::Stage(Initializer & i) : w(i), r(w){

}

Stage::~Stage(){

}

Renderer const& Stage::getRenderer() const {
  return r;
}

void Stage::draw(Texture& t){
  r.draw(t);
}

void Stage::draw(int const& x1, int const& y1, int const& x2, int const& y2){
  r.draw(x1, y1, x2, y2);
}

void Stage::draw(Object& o) {
  r.draw(o.getTexture());
}

void Stage::update() {
  r.update();
}

void Stage::clear() {
  r.clear();
}
