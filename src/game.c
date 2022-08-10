//
// Created by outtrip on 26.07.22.
//
#include "game.h"

#define X 50
#define Y 20


World init_world(){
    World world;
    world.mtx = create_mtx(X, Y);
    world.x = X;
    world.y = Y;
    return world;
}


GameData init_game() {
    GameData data;
    data.world = init_world();
    start_ncurses();
    return data;

}

void runner(GameData data){
    init_game();
    render(data.world);
}