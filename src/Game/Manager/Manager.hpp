#pragma once

#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>

#include "../Object/Object.hpp"
#include "../../Stage/Stage.hpp"
#include "../../Input/Input.hpp"
#include "../Object/Fish/Fish.hpp"
#include "../Object/Score/Score.hpp"
#include "../Object/Timer/Timer.hpp"

class Manager {
  friend class SaveManager;
  protected:
    Stage* s;
    Input* i;
    Font f;
    std::vector<Object*> draws;
    std::map<std::string, Object*> objets;

  public:
    Manager(Stage* s, Input* i);
    virtual ~Manager();
    virtual void create();
    virtual void update() = 0 ;
    virtual void render() ;
    virtual void destroy();
    void sortObject();
    Score* getScore();
    Timer* getTimer();
};

template <class Conteneur>
void empty(Conteneur& c) {
    Conteneur().swap(c);
}
