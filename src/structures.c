//
// Created by outtrip on 26.07.22.
//

#include "structures.h"
#define X 50
#define Y 20


World init_world(){
    World world;
    world.mtx = create_mtx(X, Y);
    world.x = X;
    world.y = Y;
    return world;
}
