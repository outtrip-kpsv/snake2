#ifndef SRC_PROCESS_H
#define SRC_PROCESS_H

#include <stdlib.h>
#include "structures.h"

int **create_mtx(int x, int y);
void destroy_mtx(int **mtx, int y);
void add_snake(GameData *data);
void clear_world(GameData *data);

#endif  // SRC_PROCESS_H
