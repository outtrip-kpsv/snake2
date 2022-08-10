//
// Created by outtrip on 26.07.22.
//

#ifndef STRUCTURES_STRUCTURES_H
#define STRUCTURES_STRUCTURES_H

#include "process.h"

typedef struct{
    int x;
    int y;
} init;

typedef struct{
    int ** mtx;
    int x;
    int y;
} World;

World init_world();
#endif  // STRUCTURES_STRUCTURES_H
