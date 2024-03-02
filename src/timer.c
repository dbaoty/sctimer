
#include "timer.h"
#include <curses.h>
#include <string.h>
#include <malloc.h>
#include <unistd.h>

void print_help() {
  printf("Usage:\n");
  printf(" timer.c <how long in seconds>\n");
  printf(" Ctrl-C to Quit\n");
}

int timer(int seconds_entered) {
  int hours, minutes, seconds;
  char *output_str = malloc(64 * sizeof(char));
  size_t screen_center = COLS / 2;

  while (seconds_entered >= -1) {
    hours = seconds_entered / 3600;
    minutes = (seconds_entered % 3600) / 60;
    seconds = seconds_entered % 60;

    sprintf(output_str, "+-------+ %02d:%02d:%02d +-------+", hours, minutes, seconds);
    size_t output_str_len = strlen(output_str);

    mvaddstr(10, screen_center - (output_str_len / 2), output_str);

    sleep(1);
    refresh();

    seconds_entered -= 1;
  }

  free(output_str);

  clear();
  
  mvaddstr(10, screen_center - (28 / 2), "+------+ Time's up! +------+");
  mvaddstr(LINES - 1, COLS - 22, "Press any key to quit");
  getch();

  return NO_ERROR;
}
