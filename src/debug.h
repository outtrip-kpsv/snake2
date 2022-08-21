#ifndef SNAKE_SRC_DEBUG_H_
#define SNAKE_SRC_DEBUG_H_
#include <stdio.h>
#include "structures.h"

//int create_log(FILE *fp);
FILE *create_log();
void log_print_step(GameData data);
void log_print(GameData data);
void log_print_inf(GameData data);
void log_print_world(GameData data);

#endif  // SNAKE_SRC_DEBUG_H_
