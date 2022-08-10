//
// Created by outtrip on 26.07.22.
//
#include "render.h"

void start_ncurses() {
    initscr();
}

void render(World world) {
    print_mtx(world);
    refresh();
}

void end_ncurses(){
    endwin();
}

void print_mtx(World wrld){
    for (int y = 0; y < wrld.y; y++) {
        for (int x=0; x< wrld.x; x++){
            printw("%d ",wrld.mtx[y][x]);
        }
        printw("\b\n");
    }
}