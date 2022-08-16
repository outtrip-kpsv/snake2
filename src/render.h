#ifndef SRC_RENDER_H
#define SRC_RENDER_H

#include <ncurses.h>
#include <time.h>
#include "structures.h"
#include "process.h"
#include "properties.h"

void start_ncurses();
void render(GameData data);
void end_ncurses();
void print_mtx(World world);
void print_status_frame();
void print_world_frame();
void  debug_log(GameData *data);
void print_game_over(GameData data);

#endif  // SRC_RENDER_H
