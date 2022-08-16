#include <stdio.h>
#include "game.h"

int main() {
  GameData data = init_game();
  runner(data);
  end_ncurses();
  return 0;
}
