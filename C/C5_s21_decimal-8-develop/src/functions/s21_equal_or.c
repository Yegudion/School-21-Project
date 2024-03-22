#include "../s21_decimal.h"

int s21_is_less_or_equal(s21_decimal op_1, s21_decimal op_2) {
  return !s21_is_greater(op_1, op_2);
}

int s21_is_greater_or_equal(s21_decimal op_1, s21_decimal op_2) {
  return !s21_is_less(op_1, op_2);
}
/* Return values:
    0 - FALSE
    1 - TRUE
*/