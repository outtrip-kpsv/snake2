#include "debug.h"

FILE *create_log() {
  FILE *file;
  if ((file = fopen("data.log", "w")) == NULL) {
    printf("err");
  }
  return file;
}

void log_print_step(GameData data){
  fputs("----------------------------\n", data.debug_log.log_file);
  fprintf(data.debug_log.log_file, "STEP: %ld\n", data.stat.n_step);
  fputs("----------------------------\n", data.debug_log.log_file);
}

void log_print_inf(GameData data){
  fprintf(data.debug_log.log_file, "apple: [%d:%d]\n", data.apple.x, data.apple.y);
  fputs("snake:\n", data.debug_log.log_file);
  fprintf(data.debug_log.log_file, "head: [%d:%d]\n", data.head->positions.x, data.head->positions.y);
  fprintf(data.debug_log.log_file, "length: %d\n", data.stat.snake_length);
}

void log_print_world(GameData data){
  for (int y=0; y<data.world.y; y++ ){
    for (int x=0; x<data.world.x;x++){
      switch (data.world.mtx[y][x]) {
        case 0:
          fputc(' ',data.debug_log.log_file );
          break;
        case 1:
          fputc('O',data.debug_log.log_file );
          break;
        case 2:
          fputc('+',data.debug_log.log_file );
          break;
        case 8:
          fputc('S',data.debug_log.log_file);
          break;
      }

    }
    fputc('\n',data.debug_log.log_file);
  }
  fputc('\n',data.debug_log.log_file);
}
void log_print(GameData data){
  log_print_step(data);
  log_print_inf(data);
  log_print_world(data);
}
//int main(){
//  FILE  *file = init_log();
//  if (file){
//    fputs("sss", file);
//  }
//
//  return 0;
//}