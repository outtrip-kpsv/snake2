//
// Created by outtrip on 26.07.22.
//

#include "process.h"

int ** create_mtx(int x, int y){
    int **res = calloc(y, sizeof (int*));
    for (int i = 0; i < y ; ++i) {
        res[i] = calloc(x, sizeof(int));
    }
    return res;
}

void  destroy_mtx(int **mtx, int y) {
    for (int i = 0; i <y ; ++i) {
        free(mtx[i]);
    }
    free(mtx);
}

