#include "key_handler.h"

char key_handler(GameData *data, char ch) {
  switch (ch) {
    case 'w':
      data->vector = 0;
      break;
    case 'd':
      data->vector = 1;
      break;
    case 's':
      data->vector = 2;
      break;
    case 'a':
      data->vector = 3;
      break;
  }
  return ch;
}