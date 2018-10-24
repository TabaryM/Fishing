#pragma once

#include <vector>
#include <map>
#include <string>
#include <algorithm>

#include "../Object/Object.hpp"
#include "../../Stage/Stage.hpp"
#include "../../Input/Input.hpp"

class Manager {
  protected:
    Stage* s;
    Input* i;
    std::vector<Object*> draws;
    std::map<std::string, Object*> objets;
    bool pause;

  public:
    Manager(Stage* s, Input* i);
    virtual ~Manager();
    virtual void create();
    virtual void update() = 0 ;
    virtual void render() ;
    virtual void destroy() = 0 ;
    void sortObject();
};
