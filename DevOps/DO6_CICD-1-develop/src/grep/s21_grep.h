#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_
#include <errno.h>
#include <regex.h>
#include <stdio.h>
#include <string.h>

struct type {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  int tmp_f;
  int fault1;
  int def;
  char mas_pat[100][100];
  int count;
  int count_n;
  int count_c;
  int count_e_f;
  int stat_e_f;
  int num_fail;
  int stat_l;
  int pat_1_2;
  int consilience;
};

void parcer(char *argv, struct type *opt);
void vivod_fault(struct type *opt);
void pat_f(FILE *file, struct type *opt);
void pattern1_e_and_f(char *argv, struct type *opt);
void pattern2_e_and_f(char **argv, struct type *opt);
void pat_no_e_f(char **argv, struct type *opt);
int prover_kol_file(char **argv, struct type *opt);
void parcer(char *argv, struct type *opt);
void vivod_fault(struct type *opt);
void pat_f(FILE *file, struct type *opt);
void pattern1_e_and_f(char *argv, struct type *opt);
void pattern2_e_and_f(char **argv, struct type *opt);
void pat_no_e_f(char **argv, struct type *opt);
int prover_kol_file(char **argv, struct type *opt);

#endif  // SRC_GREP_S21_GREP_H_