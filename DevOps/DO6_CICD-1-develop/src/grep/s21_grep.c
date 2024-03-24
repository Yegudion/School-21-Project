#include "s21_grep.h"

void parcer(char *argv, struct type *opt) {
  for (int j = 1; argv[j]; j++) {
    switch (argv[j]) {
      case 'e':
        opt->e = 1;
        break;
      case 'i':
        opt->i = 1;
        break;
      case 'v':
        opt->v = 1;
        break;
      case 'c':
        opt->c = 1;
        break;
      case 'l':
        opt->l = 1;
        break;
      case 'n':
        opt->n = 1;
        break;
      case 'h':
        opt->h = 1;
        break;
      case 's':
        opt->s = 1;
        break;
      case 'f':
        opt->f = 1;
        break;
      case 'o':
        opt->o = 1;
        break;
      default:
        opt->def = 1;
        break;
    }
    if (opt->e == 1 || opt->f == 1) break;
    if (opt->v == 1 || opt->l == 1) opt->o = 0;
  }
}

void vivod_fault(struct type *opt) {
  if (opt->s == 0) perror("");
}

void pat_f(FILE *file, struct type *opt) {
  int i = 0;
  if (!file) {
    vivod_fault(opt);
  } else {
    while ((opt->mas_pat[opt->count][i] = fgetc(file)) != EOF) {
      if (opt->mas_pat[opt->count][i] == '\n') {
        opt->mas_pat[opt->count][i] = '\0';
        opt->count++;
        i = 0;
      } else {
        i++;
      }
    }
  }
  if (opt->mas_pat[opt->count][i] == EOF) opt->mas_pat[opt->count][i] = '\0';
  opt->f = 0;
}

void pattern1_e_and_f(char *argv, struct type *opt) {
  char *tmp = NULL;
  FILE *file = NULL;
  for (int i = 1; argv[i]; i++) {
    if (argv[i] == 'e' && argv[i + 1] != '\0') {
      tmp = argv + (i + 1);
      strcpy(opt->mas_pat[opt->count], tmp);
      (opt->count)++;
      opt->e = 0;
      opt->pat_1_2 = 1;
    } else if (argv[i] == 'f' && argv[i + 1] != '\0') {
      tmp = argv + 2;
      file = fopen(tmp, "r");
      pat_f(file, opt);
      fclose(file);
      opt->pat_1_2 = 1;
    }
  }
}

void pattern2_e_and_f(char **argv, struct type *opt) {
  int f = 0;
  FILE *file = NULL;
  int i = 1;
  for (; argv[i]; i++) {
    if (*(argv[i]) != '\0') {
      f = 1;
      break;
    }
  }
  if (f == 0 && opt->e == 1) {
    opt->fault1 = 2;  // ошибка без шаблона
  } else if (f == 1 && opt->e == 1) {
    strcpy(opt->mas_pat[opt->count], argv[i]);
    opt->e = 0;
    (opt->count)++;
    opt->pat_1_2 = 1;
  } else if (f == 0 && opt->f == 1) {
    opt->fault1 = 2;  // ошибка без шаблона
  } else if (f == 1 && opt->f == 1) {
    file = fopen(argv[1], "r");
    pat_f(file, opt);
    fclose(file);
    opt->pat_1_2 = 2;
  }
}

void pat_no_e_f(char **argv, struct type *opt) {
  while (argv[opt->count]) {
    opt->count++;
    if (*argv[opt->count] != '-') {
      strcpy(*opt->mas_pat, argv[opt->count]);
      break;
    }
  }
  opt->count++;
}

int prover_kol_file(char **argv, struct type *opt) {
  int count = 1;
  int res = 0;
  if (opt->stat_e_f == 0) {
    count = opt->count;
  }
  for (; argv[count]; count++) {
    if (opt->stat_e_f == 1) {
      if (*argv[count] == '-') {
        for (int i = 1; argv[count][i]; i++) {
          if ((argv[count][i] == 'e' || argv[count][i] == 'f') &&
              argv[count][i + 1] == '\0') {
            count++;
            break;
          }
        }
      } else {
        res++;
      }
    }
    if (opt->stat_e_f == 0) {
      if (*argv[count] != '-') res++;
    }
  }
  return res;
}

void input(int argc, char **argv, struct type *opt) {
  for (int i = 1; i < argc; i++) {
    if (**(argv + i) == '-') {
      parcer(*(argv + i), opt);
      if (opt->f == 1) opt->tmp_f = 1;
      if (opt->e == 1 || opt->f == 1) {
        opt->stat_e_f++;
        pattern1_e_and_f(*(argv + i), opt);
      }
      if (opt->e == 1 || opt->f == 1) {
        pattern2_e_and_f(argv + i, opt);
        i++;
      }
    }
  }
  if (opt->stat_e_f == 0) {
    pat_no_e_f(argv, opt);
  }
}

void s21_strcpy(char *str, const char *istr, int n) {
  for (int i = 0; i < n; i++) {
    str[i] = istr[i];
  }
}

void obrabotka_opt_o(char *tmp, struct type *opt) {
  char *istr = NULL;
  char str[1000] = {0};
  strcpy(str, tmp);
  int n = strlen(*opt->mas_pat);
  istr = strstr(str, *opt->mas_pat);
  if (istr != NULL) {
    for (int i = 0; istr[i]; i++) {
      char str2[100] = {0};
      s21_strcpy(str2, istr, n);
      printf("%s\n", str2);
      istr = &istr[n];
      i--;
      if (strstr(istr, *opt->mas_pat) == NULL) break;
      istr = strstr(istr, *opt->mas_pat);
    }
  }
}

void vivod_po_flag(char **argv, struct type *opt, char *tmp) {
  int count = 0;
  if (opt->stat_e_f == 0)
    count = opt->count;
  else
    count = opt->count_e_f;
  if (opt->num_fail > 1 && opt->h == 0 && opt->l == 0)
    printf("%s:", argv[count]);
  if (opt->n == 1 && opt->c == 0) printf("%d:", opt->count_n);
  if (opt->c == 0 && opt->l == 0 && opt->o == 0) printf("%s", tmp);
  if (opt->c == 1) printf("%d\n", opt->count_c);
  if (opt->stat_l == 1) printf("%s", argv[count]);
}

void schit_string(char **argv, FILE *file, char *tmp, regex_t *bin_pat,
                  struct type *opt) {
  while (fgets(tmp, 900, file) != NULL) {
    opt->count_n++;
    for (int j = 0; *opt->mas_pat[j]; j++) {
      if (opt->i == 1)
        regcomp(bin_pat, opt->mas_pat[j], REG_ICASE);
      else
        regcomp(bin_pat, opt->mas_pat[j], 0);
      if ((regexec(bin_pat, tmp, 0, NULL, 0) == 0) && opt->v == 0) {
        opt->consilience = opt->count_n;
        if (opt->c == 0) vivod_po_flag(argv, opt, tmp);
        if (opt->o == 1) {
          obrabotka_opt_o(tmp, opt);
        }
        opt->count_c++;
        if (opt->l == 1) {
          opt->stat_l = 1;
        }
        break;
      } else if ((regexec(bin_pat, tmp, 0, NULL, 0) != 0) && opt->v == 1) {
        opt->consilience = opt->count_n;
        if (opt->c == 0) vivod_po_flag(argv, opt, tmp);
        if (opt->o == 1) {
          obrabotka_opt_o(tmp, opt);
        }
        opt->count_c++;
        if (opt->l == 1) {
          opt->stat_l = 1;
        }
        break;
      }
    }
    regfree(bin_pat);
    memset(tmp, 0, 1000);
    if (opt->stat_l == 1) {
      vivod_po_flag(argv, opt, tmp);
      opt->stat_l = 0;
      break;
    }
  }
}

int opt_search(char *argv) {
  int res = 0;
  for (int i = 1; argv[i]; i++) {
    if (argv[i] == 'e' || argv[i] == 'f') {
      res = 1;
      break;
    } else if (argv[i] == 'i' || argv[i] == 'v' || argv[i] == 'l' ||
               argv[i] == 'c' || argv[i] == 'h' || argv[i] == 's' ||
               argv[i] == 'o' || argv[i] == 'n') {
      res = 2;
    }
  }
  return res;
}

void vivod_no_e_f(char **argv, FILE *file, struct type *opt, char *tmp,
                  regex_t *bin_pat) {
  for (; argv[opt->count]; opt->count++) {
    if (*(argv[opt->count]) != '-') {
      file = fopen(argv[opt->count], "r");
      if (!file) {
        opt->fault1 = 1;
      } else {
        schit_string(argv, file, tmp, bin_pat, opt);
        if (opt->c == 1) vivod_po_flag(argv, opt, tmp);
        if (opt->consilience == opt->count_n && opt->c == 0 && opt->o == 0)
          printf("\n");  // sovp s posled
        opt->count_n = 0;
        opt->count_c = 0;
        fclose(file);
      }
    }
  }
}

void osnov_chast(char **argv, struct type *opt, int argc) {
  regex_t bin_pat;
  char tmp[1000] = {0};
  FILE *file = NULL;
  opt->num_fail = prover_kol_file(argv, opt);
  if (opt->stat_e_f == 0) {
    vivod_no_e_f(argv, file, opt, tmp, &bin_pat);
  } else {
    for (opt->count_e_f = 1; opt->count_e_f < argc; opt->count_e_f++) {
      if (*(argv[opt->count_e_f]) == '-') {
        if (opt_search(argv[opt->count_e_f]) == 1) {
          if (opt->pat_1_2 == 1) {
            opt->count_e_f++;
            continue;
          }
          if (opt->pat_1_2 == 2) {
            opt->count_e_f++;
            continue;
          }
        } else if (opt_search(argv[opt->count_e_f]) == 2) {
          opt->count_e_f++;
        }
      }
      if (opt->count_e_f == argc) break;
      file = fopen(argv[opt->count_e_f], "r");
      if (file) {
        schit_string(argv, file, tmp, &bin_pat, opt);
        if (opt->c == 1) vivod_po_flag(argv, opt, tmp);
        if (opt->consilience == opt->count_n && opt->c == 0 && opt->o == 0)
          printf("\n");  // sovp s posled
        opt->count_n = 0;
        opt->count_c = 0;
        fclose(file);
      } else {
        vivod_fault(opt);
      }
    }
  }
}

int main(int argc, char **argv) {
  struct type opt = {0};
  input(argc, argv, &opt);
  osnov_chast(argv, &opt, argc);
  return 0;
}