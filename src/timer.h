#ifndef TIMER_H
#define TIMER_H

#define MAX_TIME_INPUT (359999)

enum EXIT_CODES {
  NO_ERROR,
  ARG_COUNT_ERROR,
  TIME_INPUT_ERROR,
  EXIT_CODES_COUNT,
};

void print_help();
int timer(int);

#endif // !TIMER_H
