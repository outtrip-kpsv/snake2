//
// Created by outtrip on 26.07.22.
//
#include "game.h"



void init_game() {
    start_ncurses();
}

void runner(World world){
    init_game();
    render(world);
}