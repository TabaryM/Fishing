#pragma once

#include "../../../Texture/Surface/Rectangle/Rectangle.hpp"
#include "../../Object/Object.hpp"
#include "../../Object/Fish/Fish.hpp"
#include "../../Object/Boat/Boat.hpp"
#include "../../Object/Hook/Hook.hpp"
#include "../../Object/Wave/Wave.hpp"
#include "../Manager.hpp"

class GameManager : public Manager {
  private:
    int speed;
    int nbFish;
    Rectangle borders;

  public:
    GameManager(Stage* s, Input* i);
    ~GameManager() = default;
    void create() override;
    void update() override;
    void render() override;
    void destroy() override;
    void updateControlX(Object* obj);
    void updateControlY(Object* obj);

};
