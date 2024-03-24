#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cat_fl {
  int b_min;
  int e_min;
  int E_min;
  int n_min;
  int s_min;
  int t_min;
  int T_min;
  int v_min;
  int disapp;
} cat_fl;

int flags_parser(int argc, char** argv, cat_fl* cat_flags);
void processing_accepted_arguments(int argc, char** argv, cat_fl* cat_flags);
int file_character_printing(FILE* f_ptr, char* name_of_file, cat_fl* cat_flags);

#endif  // SRC_CAT_S21_CAT_H_