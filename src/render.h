//
// Created by outtrip on 26.07.22.
//

#ifndef SRC_RENDER_H
#define SRC_RENDER_H

#include <ncurses.h>
#include "structures.h"

void start_ncurses();
void render(World world);
void end_ncurses();
void print_mtx(World wrld);

#endif  // SRC_RENDER_H
