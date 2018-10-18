#pragma once

#include "../../Object/Object.hpp"
#include "../../Object/Fish/Fish.hpp"
#include "../../Object/Boat/Boat.hpp"
#include "../../Object/Hook/Hook.hpp"
#include "../Manager.hpp"

class GameManager : public Manager {
  private:
    int speed;
    Rectangle borders;

  public:
    GameManager(Stage* s, Input* i);
    ~GameManager();
    void create() override;
    void update() override;
    void render() override;
    void destroy() override;
    void updateControl(Object* obj);

};
