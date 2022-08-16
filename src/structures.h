#ifndef STRUCTURES_STRUCTURES_H
#define STRUCTURES_STRUCTURES_H

#include <time.h>

typedef struct {
    int x;
    int y;
} init;

typedef struct {
    int **mtx;
    int x;
    int y;
} World;

typedef struct {
    int x;
    int y;
} Positions;

struct Node {
    struct Node *node;
    Positions positions;
};

typedef struct {
    int score;
    int status;
    // 0 - menu
    // 1 -
    // 2 - game
    // 10 - game over
    int level;
    int snake_length;
    int spaced_fill;
} Stat;

typedef struct {
  int rand;
  int x_apple;
  int y_apple;
} Debug_log;

typedef struct {
    World world;
    struct Node *head;
    int vector;
    Stat stat;
    int time_step;
    Positions apple;
    int create_apple;
    Debug_log debug_log;

} GameData;



#endif  // STRUCTURES_STRUCTURES_H
