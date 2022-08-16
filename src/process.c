#include "process.h"
#include <ncurses.h>


int **create_mtx(int x, int y) {
    int **res = calloc(y, sizeof(int *));
    for (int i = 0; i < y; ++i) {
        res[i] = calloc(x, sizeof(int));
    }
    return res;
}

void destroy_mtx(int **mtx, int y) {
    for (int i = 0; i < y; ++i) {
        free(mtx[i]);
    }
    free(mtx);
}

void add_snake(GameData *data) {
    struct Node *tmp = data->head;
    data->world.mtx[data->head->positions.y][data->head->positions.x] = 2;
    data->head = data->head->node;
    for (; data->head; data->head = data->head->node) {
        data->world.mtx[data->head->positions.y][data->head->positions.x] = 1;
    }
    data->head = tmp;
}

void clear_world(GameData *data) {
    for (int i = 0; i < data->world.y; i++) {
        for (int j = 0; j < data->world.x; j++) {
            data->world.mtx[i][j] = 0;
        }
    }
}