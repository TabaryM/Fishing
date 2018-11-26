/**
 * @file GameManager.hpp
 * @author Paul-Emile Watelot, Christian Vasaune, Mathieu Tabary
 */
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
#include "../../Object/Wave/Wave.hpp"
#include "../Manager.hpp"

/**
 * @class GameManager
 * @brief Camera's Object : Manage and update all Objects in Game
 */
class GameManager : public Manager {
  private:
    int speed;
    int profondeur;
    int focus;
    Rectangle borders;
    std::vector<Fish*> fishs;

  public:
    //## Constructor #//
      /**
       * Construct with a stage and an input
       * @param s the Stage
       * @param i the Input
       */
    GameManager(Stage* s, Input* i);
    //## Deconstructor ##//
    /**
     * GameManager Deconstructor
     */
    ~GameManager() = default;
    //## Methods ##//

    void create() override;
    void update() override;
    void render() override;
    void destroy() override;
    void updateControlX(Object* obj);
    void updateControlY(Object* obj);
    std::vector<Fish*>& getFishs();
    void fillFish();

};
