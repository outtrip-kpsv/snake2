#ifndef SRC_GAME_H
#define SRC_GAME_H

#include "process.h"
#include "render.h"
#include "debug.h"
#include "structures.h"
#include "properties.h"
#include "snake.h"
#include "key_handler.h"

#include <ncurses.h>

GameData init_game();
World init_world();
void runner(GameData data);
Stat init_stat();

#endif  // SRC_GAME_H
