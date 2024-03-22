#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int bit_1;
  int sign_1 = 0;
  s21_get_dec_sign(value_1, &sign_1);
  int sign_2 = 0;
  s21_get_dec_sign(value_2, &sign_2);
  s21_decimal adder = value_1;
  int exp1;
  int exp2;
  int error = 0;
  exp1 = s21_10_conv(value_1);
  exp2 = s21_10_conv(value_2);
  s21_rev_10_conv(result, exp1 + exp2);
  set_0_bit(&adder.bits[3], 31);  // модуль копии вал_1
  for (int i = 0; i < 3; i++) {  // проходимся по всей мантисе
    for (int j = 0; j < 32; j++) {
      bit_1 = test_bit(value_2.bits[i], j);
      if (bit_1) {
        s21_addiction_logic(*result, adder, result);  // ---?
      }
      error = s21_shift(&adder);
    }
  }
  if (sign_1 != sign_2)
    set_1_bit(&result->bits[3], 31);
  else
    set_0_bit(&result->bits[3], 31);
  return error;
}

/* Данная функция делает смещение числа типа decimal
вперёд на один символ. Нужна при выполнении операции умножения */
int s21_shift(s21_decimal *number) {
  int vault_1 = 0;  // Хранит значение предыдущего бита
  int vault_2 = 0;  // Сохраняет нынешний бит
  int error = test_bit(number->bits[2], 31);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 32; j++) {
      vault_2 = test_bit((number->bits[i]), j);
      if (vault_1)
        set_1_bit(&number->bits[i], j);
      else
        set_0_bit(&number->bits[i], j);
      vault_1 = vault_2;
    }
  }
  return error;
}

/* return error codes:
    0 - OK
    1 - the number is too large or equal to infinity
    2 - the number is too small or equal to negative infinity
    3 - division by 0
*/