#include "header.h"

int main() {
  char enter_str[N]; //начальная строка
  scanf("%[^=]s", enter_str);

  check_and_clean(enter_str);
  return 0;
}