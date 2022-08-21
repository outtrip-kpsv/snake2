
#include "game.h"
#include <stdio.h>

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
  stat.snake_length = SNAKE_LENGTH;
  stat.spaced_fill = Y * X - stat.snake_length;
  stat.n_step = 1;
  return stat;
}

GameData init_game() {
  GameData data;
  data.world = init_world();
  data.head = init_snake();
  data.stat = init_stat();
  data.vector = 0;
  data.time_step = clock();
  data.create_apple = 1;
  start_ncurses();
  if (DEBUG) {
    data.debug_log.log_file = create_log();
  }
  return data;
}

void runner(GameData data) {
  char ch = ' ';
  while (ch != 'q') {
    ch = (char) getch();
    key_handler(&data, ch);
    if (data.create_apple) create_apple(&data);
    if (clock() - data.time_step >= 500000 - 50000 * data.stat.level) {
      if(DEBUG){
        log_print(data);
      }
      snake_step(&data, data.vector);
      data.time_step = clock();
    }
    render(&data);
  }
  destroy_mtx(data.world.mtx, data.world.y);
  end_ncurses();
  printf("lll");

}
