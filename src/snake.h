#ifndef SRC_SNAKE_H
#define SRC_SNAKE_H

#include "structures.h"
#include "properties.h"
#include <stdlib.h>

struct Node *add_node(struct Node *node, int vector);
struct Node *init_snake();
struct Node *snake_step(GameData *data, int vector);
struct Node *snake_step2(struct Node *head, int vector);

#endif  // SRC_SNAKE_H
