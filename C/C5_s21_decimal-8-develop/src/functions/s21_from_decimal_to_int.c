#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error = 0;
  s21_decimal src_trunc;
  s21_truncate(src, &src_trunc);
  if ((src_trunc.bits[2] == 0) && (src_trunc.bits[1] == 0)) {
    *dst = src_trunc.bits[0];

    int sign = 0;
    s21_get_dec_sign(src_trunc, &sign);
    if (sign) (*dst) *= -1;

  } else {
    error = 1;
  }

  return error;
}
