#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  for (int i = 0; i < 4; i++) {
    result->bits[i] = value.bits[i];
  }
  int sign;
  int error = s21_get_dec_sign(value, &sign);
  if (!error) error = s21_set_dec_sign(result, !sign);

  return error;
}
