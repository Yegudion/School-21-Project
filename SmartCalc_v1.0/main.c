#include "func.h"

int main() {
  char enter_str[N]; //начальная строка
  scanf("%[^=]s", enter_str);

  check_and_clean(enter_str);
  printf("%s", enter_str);
  return 0;
}