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

typedef struct {
    int x;
    int y;
} Positions;

typedef struct {
    struct Node * node;
    Positions positions;
} Node;

typedef struct {
    World world;
} GameData;

#endif  // STRUCTURES_STRUCTURES_H
