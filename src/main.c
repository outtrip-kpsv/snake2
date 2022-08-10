#include <stdio.h>
#include "game.h"
#include "structures.h"

int main() {
    World world= init_world();
//    printf("%d", world.x);
    runner(world);
    return 0;
}
