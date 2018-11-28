#pragma once

#include <ctime>
#include "../GameManager/GameManager.hpp"

class SaveManager {
  protected:
    Stage* s;
  public:
    SaveManager(Stage* s);
    ~SaveManager() = default;

    void save(Score* sc);
    void load(std::vector<Fish*>& fishs, Score* score, Timer* timer);
};
