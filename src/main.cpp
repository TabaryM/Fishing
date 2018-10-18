#include "Game/Game.hpp"

int main(int argc, char **argv) {
  Initializer i;
  Game game(i);

  game.mainLoop();

  return 0;
}
