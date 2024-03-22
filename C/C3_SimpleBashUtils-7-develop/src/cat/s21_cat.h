#ifndef S21_CAT
#define S21_CAT

#include <fcntl.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
  int number;
  int number_nonblank;
  int squeeze_blank;
  int show_ends;
  int show_nonprinting;
  int show_tabs;
} actions;

void usage(char* program_name);
void cat(actions* a, int* fd, int* count_starts_of_line, int* start_of_line);

#endif