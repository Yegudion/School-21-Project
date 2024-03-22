#include <string.h>

#include "../s21_decimal.h"

int s21_div(s21_decimal v1, s21_decimal v2, s21_decimal *result) {
  (void)v1;

  if (!v2.bits[0] && !v2.bits[1] && !v2.bits[2]) {
    return RESULT_DIV_BY_ZERO;
  }

  memset(result->bits, 0, sizeof(int) * 4);
  return RESULT_OK;
}