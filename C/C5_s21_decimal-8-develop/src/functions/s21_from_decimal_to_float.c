#include "../s21_decimal.h"

int s21_get_exp(s21_decimal *src) { return (src->bits[3] & 0xFF0000) >> 16; }

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  *dst = 0;
  for (int i = 0; i < 96; i++) {
    if (scan_single_bit(src, i)) {
      *dst += scan_single_bit(src, i) * pow(2, i);
    }
  }
  *dst /= pow(10, s21_get_exp(&src));
  int sign;
  s21_get_dec_sign(src, &sign);
  if (sign) {
    *dst = -*dst;
  }
  return 0;
}
