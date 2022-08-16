#include "render.h"

void start_ncurses() {
//    initscr();
  nodelay(initscr(), 1);
  start_color();

  init_pair(1, COLOR_RED, COLOR_YELLOW);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_RED);
  init_pair(10, COLOR_BLUE, COLOR_GREEN);

}

void render(GameData data) {
  switch (data.stat.status) {
    case 2:clear_world(&data);
      add_snake(&data);
      add_apple(&data);
      print_world_frame();
      print_mtx(data.world);
      print_status_frame(data);
      debug_log(&data);
      break;
    case 10:
      print_world_frame();
      print_mtx(data.world);
      print_game_over(data);
      break;
  }
  refresh();
}

void end_ncurses() {
  endwin();
}

void print_mtx(World world) {
  move(1, 1);
  for (int y = 0; y < world.y; y++) {
    move(1 + y, 1);
    for (int x = 0; x < world.x; x++) {
      switch (world.mtx[y][x]) {
        case 0:
          attron(COLOR_PAIR(2));
          printw("%c", FILL_SPASE);
          break;
        case 1:
          attron(COLOR_PAIR(1));
          printw("%c", FILL_SNAKE);
          break;
        case 2:
          attron(COLOR_PAIR(3));
          printw("%c", FILL_HEAD);
          break;
        case 8:
          attron(COLOR_PAIR(2));
          printw("%c", FILL_EAT);
          break;
      }
    }
  }
}

void print_world_frame() {
  move(0, 0);
  attron(COLOR_PAIR(10));
  for (int i = 0; i < Y + 2; i++) {
    for (int j = 0; j < X + 2; j++) printw(" ");
    printw("\n");
  }
}

void print_status_frame() {
  attron(COLOR_PAIR(3));
  move(1, X + 3);
  printw("____________________");
  move(2, X + 3);
  attron(COLOR_PAIR(3));
  printw("|                  |");
  move(3, X + 3);
  attron(COLOR_PAIR(3));
  printw("|                  |");
}

void debug_log(GameData *data) {
  move(Y + 5, 0);
  printw("[%d %d]", data->head->positions.y, data->head->positions.x);
  struct Node * tmp = data->head;
  printw("\n");
  for (;tmp;tmp=tmp->node){
    printw("{%d:%d} ", tmp->positions.y, tmp->positions.x);
  }
  printw("\n|%d|", data->debug_log.rand);
}

void print_game_over(GameData data){
  move(2, 5);
  printw("GAME OVER");
  move(3, 6);
  printw("score: %d", data.stat.score);
}
