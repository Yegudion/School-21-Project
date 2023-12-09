#ifndef HEADER
#define HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define INCORRECT 1

#define N 256
#define symbol_etalon                                                          \
  "mod cos sin tan atan acos asin atan sqrt ln log x e E . 1234567890 () ^ + " \
  "-* /"
#define functions "mo co si ta at ac as at sq ln lo"
#define binary "( ) ^ + - * /"
//"mod cos sin tan atan acos asin atan sqrt ln log"

struct data {
  double value;
  int priority;
  char cell_type[2];
};
typedef struct data data;

struct cell {
  data cell_data;
  struct cell *next;
};

struct cell *append_cell(data cell_data, struct cell *next);
struct cell *create_cell(data cell_data);
void reverse(struct cell **head);
data pop(struct cell *stack);

/*prioir:
0: - x or numbers
1: - +
2: * / mod
3: ^
4: cos sin tan atan acos asin atan sqrt ln log
*/

//проверка и отчистка строки перед обработкой
int check_and_clean(char str[N]);

//отчистка от пробелов
void clean_space(char str[N]);

struct cell *parser(char str[N]);

double calc_RPN(struct cell *stack);

#endif
