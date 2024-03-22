#include <math.h>

#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  for (int i = 0; i < 4; i++) {
    result->bits[i] = 0;
  }

  s21_decimal minus_null = {{0, 0, 0, 0}};
  s21_set_dec_sign(&minus_null, 1);

  int error = 0;
  int sign;
  int scale;
  s21_decimal sub_one = {{1, 0, 0, 0}};

  if (!s21_get_dec_sign(value, &sign) &&
      !s21_get_dec_scale_factor(value, &scale)) {
    s21_truncate(value, result);
    if (sign != 0 && !s21_is_equal(*result, value) &&
        !s21_is_equal(value, minus_null)) {
      s21_sub(*result, sub_one, result);
    }
  } else
    error = 1;
  return error;
}

/* Return error codes:
    0 - OK
    1 - error
*/
