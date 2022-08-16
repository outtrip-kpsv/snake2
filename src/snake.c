#include "snake.h"
#include <stdio.h>

Positions go_vector(int vector) {
  Positions v;
  switch (vector) {
    case 0:v.x = 0;
      v.y = -1;
      break;
    case 1:v.x = 1;
      v.y = 0;
      break;
    case 2:v.x = 0;
      v.y = 1;
      break;
    case 3:v.x = -1;
      v.y = 0;
      break;
  }
  return v;
}

struct Node *init_snake() {
  int head_x = X / 2;
  int head_y = Y / 2 + SNAKE_LENGTH / 2 - 1;
  struct Node *head = calloc(1, sizeof(struct Node));
  head->positions.x = head_x;
  head->positions.y = head_y;
  head->node = NULL;
  for (int i = 0; i < SNAKE_LENGTH - 1; i++) {
    head = add_node(head, 0);
  }
  return head;
}

struct Node *add_node(struct Node *node, int vector) {
  Positions v = go_vector(vector);
  struct Node *res = calloc(1, sizeof(struct Node));
  res->positions.x = node->positions.x + v.x;
  res->positions.y = node->positions.y + v.y;
  res->node = node;
  return res;
}

struct Node *snake_step(GameData *data, int vector) {
  printf("!! %d\n", data->head->positions.y);
  Positions v = go_vector(vector);
  struct Node *res = calloc(1, sizeof(struct Node));

  res->positions.x = data->head->positions.x + v.x;
  res->positions.y = data->head->positions.y + v.y;
  if (res->positions.y > Y - 1
      || res->positions.y < 0
      || res->positions.x > X - 1
      || res->positions.x < 0
      || snake_cross(&res->positions,data->head)) {
    data->stat.status = 10;
  } else {
    if(data->head->positions.x == data->apple.x && data->head->positions.y == data->apple.y){
      res->node = data->head;
      data->head = res;
      data->create_apple = 1;
    } else {
      res->node = data->head;
      data->head = res;

      for (; data->head->node->node; data->head = data->head->node) {}
      free(data->head->node->node);
      data->head->node = NULL;
      data->head = res;
    }

  }

  return data->head;
}

int snake_cross(Positions *start, struct Node *head) {
  int res = 0;
  for (; head; head = head->node) {
    if (start->x == head->positions.x && start->y == head->positions.y) res = 1;
  }
  return res;
}