#include "Manager.hpp"

Manager::Manager(Stage* s, Input* i) : s(s), i(i), f() {}

Manager::~Manager(){
  destroy();
}

void Manager::create(){
  sortObject();
}

void Manager::destroy(){
    for (auto& it : objets) {
        delete it.second;
        it.second = nullptr;
    }
}

void Manager::render(){
  for (Object* o : draws) {
    if(o->isActive()){
      if(o->isFliped()){
        s->flip(*o);
      }else{
        s->draw(*o);
      }
    }
  }
}

void Manager::sortObject() {
  empty(draws);
  //std::vector<Object*>().swap(draws);
  for (auto& o : objets) {
    draws.push_back(o.second);
  }
  std::sort(draws.begin(), draws.end(), Object::ObjectCompare());
}

Score* Manager::getScore(){
  return static_cast <Score*>(objets["Score"]);
}

Timer* Manager::getTimer(){
  return static_cast <Timer*>(objets["Timer"]);
}
