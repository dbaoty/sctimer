
#include "timer.h"

#include <curses.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
  if (argc != 2) {
    print_help();
    return ARG_COUNT_ERROR;
  }

  if (strcmp(*(argv + 1), "-h") == 0) {
    print_help();
    return NO_ERROR;
  }

  int seconds_entered = atoi(*(argv + 1));
  if (!seconds_entered) {
    print_help();
    return TIME_INPUT_ERROR;
  }

  initscr();
  cbreak();
  noecho();

  if (seconds_entered > MAX_TIME_INPUT) {
    timer(MAX_TIME_INPUT);
    endwin();
    return NO_ERROR;
  }

  timer(seconds_entered);

  endwin();
  return NO_ERROR;
}
