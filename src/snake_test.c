#include "snake.h"
#include "structures.h"
#include <stdio.h>

void print_snake(struct Node *head);

int main() {
//    struct Node *head = init_head();
  GameData data;
  data.head = init_snake();
  print_snake(data.head);
  printf("------\n");
  snake_step(&data, 0);
  print_snake(data.head);
  return 0;
}

void print_snake(struct Node *head) {
  struct Node *tmp = head;
  for (; head; head = head->node) {
    printf("%d-%d\n", head->positions.x, head->positions.y);
  }
  head = tmp;
}