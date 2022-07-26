//
// Created by outtrip on 26.07.22.
//

#include "render.h"

void start_ncurses() {
    initscr();
}

void render() {
    printw("dd");
}

void end_ncurses(){
    endwin();
}