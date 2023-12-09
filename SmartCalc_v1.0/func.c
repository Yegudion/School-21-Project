#include "header.h"

void clean_space(char str[N]) {
  int new_len = 0;
  char new_str[N];
  for (int i = 0; i < N; i++) {
    if (str[i] != ' ' || str[i] != '\n') {
      new_str[new_len] = str[i];
      new_len++;
    }
  }
  strcpy(str, new_str);
}

int check_and_clean(
    char str[N]) { //добавить проверку чтобы перед точкой стояло число
  int error = OK;
  clean_space(str);
  int i = 0;
  int left_scope = 0, rigth_scope = 0;

  while (i < N && str[i] != '\0') {
    if (str[i] == '(')
      left_scope++;

    if (str[i] == ')')
      rigth_scope++;

    char sub_str[4] = {0};
    if (str[i] == 'a' || (str[i] == 's' && str[i + 1] == 'q')) {
      strncpy(sub_str, str + i, 4);
      if (!strstr(symbol_etalon, sub_str)) {
        error = INCORRECT;
        break;
      }
      i += 4;
    } else if (str[i] == 'c' || str[i] == 's' || str[i] == 't' ||
               (str[i] == 'l' && str[i + 1] == 'o')) {
      strncpy(sub_str, str + i, 3);
      if (strstr(symbol_etalon, sub_str) == NULL) {
        error = INCORRECT;
        break;
      }
      i += 3;
    } else if (str[i] == 'l') {
      strncpy(sub_str, str + i, 2);
      if (!strstr(symbol_etalon, sub_str)) {
        error = INCORRECT;
        break;
      }
      i += 2;
    } else if (!strchr(symbol_etalon, (int)str[i])) {
      error = INCORRECT;
      break;
    } else {
      i++;
    }
  }
  if (left_scope != rigth_scope)
    error = INCORRECT;
  return error;
}

data functions_parser(char str[N], int *i) {
  char sub_str[2] = {0};
  data cell_data = {0, 0, 0};

  strncpy(sub_str, str + *i, 2);
  while (functions[*i + 1] != '\0') {
    if (functions[*i] == sub_str[*i % 2] &&
        functions[*i + 1] == sub_str[*i % 2 + 1]) {

      strcpy(cell_data.cell_type, sub_str);
      cell_data.priority = 4;
      if (str[*i] == 'm')
        cell_data.priority = 2;
      cell_data.value = 0;
    }
    i++;
  }
  return cell_data;
}

data binary_parser(char str, int *i) {
  data cell_data = {0, 0, 0};
  cell_data.cell_type[0] = str[*i];
  cell_data.value = 0;

  switch (str[*i]) {
  case '(':
    cell_data.priority = 4;
    break;
  case ')':
    cell_data.priority = 4;
    break;
  case '^':
    cell_data.priority = 3;
    break;
  default: // * / + -
    cell_data.priority = 2;
    break;
  }

  return cell_data;
}

struct cell *parser(char str[N]) {
  int i = 0;
  struct cell *next;

  while (str[i] != '\0') {
    struct cell cells;
    data cell_data = {0, 0, 0};

    if (strchr(functions, (int)str[i])) {
      functions_parser(str, &i);

    } else if (strchr(binary, (int)str[i])) {
      binary_parser(str[i], &i);

    } else if (str[i] == 'x') {
      cell_data.value = 0;
      cell_data.cell_type[0] = 'x';
      cell_data.priority = 0;

      i++;
    } else {
      cell_data.value = strtod(str + i, str);
      cell_data.cell_type[0] = 'n';
      cell_data.priority = 0;
      i = 0;
    }

    if (next) {
      next = append_cell(cell_data, next);
    } else {
      next = create_cell(cell_data);
    }
  }
}