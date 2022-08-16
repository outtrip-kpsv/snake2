#include "key_handler.h"

char key_handler(GameData *data, char ch) {
  switch (ch) {
    case 'w':
      if (data->vector != 2){
        data->vector = 0;
      }
      break;
    case 'd':
      if (data->vector != 3){
        data->vector = 1;
      }
      break;
    case 's':
      if (data->vector != 0){
        data->vector = 2;
      }
      break;
    case 'a':
      if (data->vector != 1){
        data->vector = 3;
      }
      break;
  }
  return ch;
}