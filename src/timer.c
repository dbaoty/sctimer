
#include "timer.h"
#include <curses.h>

void print_help() {
  printf("Usage:\n");
  printf(" timer.c <how long in seconds>\n");
  printf(" Ctrl-C to Quit\n");
}

int timer(int seconds_entered) {
  int hours, minutes, seconds;

  while (seconds_entered >= -1) {
    hours = seconds_entered / 3600;
    minutes = (seconds_entered % 3600) / 60;
    seconds = seconds_entered % 60;

    move(0, 0);
    printw("+----------+ %02d:%02d:%02d +----------+\n", hours, minutes, seconds);

    sleep(1);
    refresh();

    seconds_entered -= 1;
  }

  move(0, 0);
  printw("+----------+ Time's up! +----------+\n");
  getch();

  return NO_ERROR;
}
