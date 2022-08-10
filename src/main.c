#include <stdio.h>
#include "game.h"

int main() {
    GameData data = init_game();
    runner(data);
    return 0;
}
