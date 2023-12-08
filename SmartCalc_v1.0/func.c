#include "func.h"

void clean_space(char str[N]) {
  int new_len = 0;
  char new_str[N];
  for (int i = 0; i < N; i++) {
    if (str[i] != ' ') {
      new_str[new_len] = str[i];
      new_len++;
    }
  }
  strcpy(str, new_str);
}

int check_and_clean(char str[N]) {
  int error = OK;
  clean_space(str);
  char *symbol_etalon =
      "x . 1234567890 cos sin tan atan acos asin atan sqrt ln log () ^ + - * /";
  int i = 0;
  int left_scope = 0, rigth_scope = 0;
  while (i < N) {
    if (str[i] == 'a' || (str[i] == 's' && str[i + 1] == 'q')) {
      char sub_str[4];
      strncpy(sub_str, str + i, 4);
      if (!strstr(symbol_etalon, sub_str)) {
        error = INCORRECT;
        break;
      }
      i += 4;
    } else if (str[i] ==
                   'c' || str[i] == 's' || str[i] == 't' || str[i] == 'l') {
      char sub_str[3];
      strncpy(sub_str, str + i, 3);
      if (!strstr(symbol_etalon, sub_str)) {
        error = INCORRECT;
        break;
      }
      i += 3;
    } else if (str[i] == 'l') {
      char sub_str[2];
       strncpy(sub_str, str + i, 2);
      if (!strstr(symbol_etalon, sub_str)) {
        error = INCORRECT;
        break;
      }
      i += 2;
    } else if (!strstr(symbol_etalon, &str[i])) {
      error = INCORRECT;
      break;
    }

    if (str[i] == '(')
      left_scope++;

    if (str[i] == ')')
      rigth_scope++;

    i++;
  }
  if (left_scope != rigth_scope)
    error = INCORRECT;
  return error;
}