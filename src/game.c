
#include "game.h"

World init_world() {
  World world;
  world.mtx = create_mtx(X, Y);
  world.x = X;
  world.y = Y;
  return world;
}

Stat init_stat() {
  Stat stat;
  stat.level = 1;
  stat.score = 0;
  stat.status = 2;
  return stat;
}

GameData init_game() {
  GameData data;
  data.world = init_world();
  data.head = init_snake();
  data.stat = init_stat();
  data.vector = 0;
  data.time_step = clock();
  start_ncurses();
  return data;
}

void runner(GameData data) {
//    init_game();
  char ch = ' ';
  while (ch != 'q') {
    ch = (char) getch();
    key_handler(&data, ch);
    if (clock() - data.time_step >= 800000 - 50000 * data.stat.level) {
      snake_step(&data, data.vector);
      data.time_step = clock();
    }
    render(data);
  }
  destroy_mtx(data.world.mtx, data.world.y);
  end_ncurses();

}
