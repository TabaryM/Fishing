#include "Game/Game.hpp"

int main(int argc, char **argv) {
  Initializer i;
  Game game(i);

  game.launch();

  return 0;
}
