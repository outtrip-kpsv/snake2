//
// Created by outtrip on 26.07.22.
//

#ifndef SRC_GAME_H
#define SRC_GAME_H

#include "process.h"
#include "render.h"
#include "structures.h"

GameData init_game();
World init_world();
void runner(GameData data);

#endif  // SRC_GAME_H
