#include "func.h"

int main() {
  char enter_str[N]; //начальная строка
  scanf("%[^=]s", enter_str);

  int status=check_and_clean(enter_str);
  printf("%s\n status=%d ", enter_str, status);
  return 0;
}