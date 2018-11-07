#pragma once

#include "../../../Texture/Surface/Rectangle/Rectangle.hpp"
#include "../../Object/Object.hpp"
#include "../../Object/Fish/Fish.hpp"
#include "../../Object/Fish/NormalFish/NormalFish.hpp"
#include "../../Object/Fish/FastFish/FastFish.hpp"
#include "../../Object/Fish/GoldFish/GoldFish.hpp"
#include "../../Object/Fish/RipFish/RipFish.hpp"
#include "../../Object/Fish/BombFish/BombFish.hpp"
#include "../../Object/Fish/JebaiFish/JebaiFish.hpp"
#include "../../Object/Boat/Boat.hpp"
#include "../../Object/Hook/Hook.hpp"
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
