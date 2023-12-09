#include "header.h"

int main() {
  char enter_str[N]; //начальная строка
  scanf("%[^=]s", enter_str);

  if(!check_and_clean(enter_str)){
    printf("correct");
    struct cell *stack = parser(enter_str);
    calc_RPN(stack);

  }else{
    printf("incorrect");
  }
  return 0;
}