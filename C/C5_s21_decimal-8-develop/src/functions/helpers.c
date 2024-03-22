#include "../s21_decimal.h"

int test_bit(unsigned int value, int BitNumber) {
  return value & (1 << BitNumber);
}

int s21_10_conv(s21_decimal value) {
  int result = 0;
  int power = 1;
  for (int i = 16; i < 21; i++, power = power * 2)
    if (test_bit(value.bits[3], i)) {
      result = result + power;
    }
  return result;
}

void s21_rev_10_conv(s21_decimal *value, int result) {
  int power = 16;
  for (int i = 20; i > 15; i--, power /= 2)
    if (result >= power) {
      result -= power;
      set_1_bit(&value->bits[3], i);
    } else {
      set_0_bit(&value->bits[3], i);
    }
}

/* Данная функция - shift наоборот, смещает мантису decimal влево */
void s21_unshift(s21_decimal *number) {
  int vault_1 = 0;  // Хранит значение предыдущего бита
  int vault_2 = 0;  // Сохраняет нынешний бит
  for (int i = 2; i >= 0; i--) {
    for (int j = 31; j >= 0; j--) {
      vault_2 = test_bit((number->bits[i]), j);
      if (vault_1)
        set_1_bit(&number->bits[i], j);
      else
        set_0_bit(&number->bits[i], j);
      vault_1 = vault_2;
    }
  }
}

int s21_addiction_logic(s21_decimal value_1, s21_decimal value_2,
                        s21_decimal *result) {
  int a = 0;     // бит первого числа
  int b = 0;     // бит второго числа
  int prev = 0;  // была ли единица в уме
  int next = 0;  // будем ли мы передавать единицу в след разряд
  int res;  // бит который мы запишем в результат

  int error = 0;
  a = test_bit(value_1.bits[2], 31);
  b = test_bit(value_2.bits[2], 31);

  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 32; i++) {
      /*  int test_bit(int value, int BitNumber) { return value & (1 <<
       * BitNumber); }  */
      // проверка бита
      a = test_bit(value_1.bits[j], i);
      b = test_bit(value_2.bits[j], i);
      if (a == 0) {
        if (b == 0 && prev == 0) {
          res = 0;
          next = 0;
        } else if (b == 0 || prev == 0) {
          res = 1;
          next = 0;
        } else {
          res = 0;
          next = 1;
        }
      } else {
        if (b == 0 && prev == 0) {
          res = 1;
          next = 0;
        } else if (b == 0 || prev == 0) {
          res = 0;
          next = 1;
        } else {
          res = 1;
          next = 1;
        }
      }
      prev = next;
      /*  посе того как получили res - выставляем в num3 */
      if (res) {
        /*  set_1_bit(int *value, int BitNumber) { *value = *value | (1 <<
         * BitNumber); } */
        set_1_bit(&(result->bits[j]), i);
      } else {
        /*  set_0_bit(int *value, int BitNumber) { *value = *value & ~(1 <<
         * BitNumber); } */ // ЧТО ТАКОЕ "~" И КАК ОНА РАБОТАЕТ
        set_0_bit(&(result->bits[j]), i);
      }
    }
  }
  return error;
}

void set_1_bit(unsigned int *value, int BitNumber) {
  *value |= (1 << BitNumber);
}

void set_0_bit(unsigned int *value, int BitNumber) {
  *value &= ~(1 << BitNumber);
}

int s21_zero(s21_decimal value) {
  int bit = 0;
  int error = 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 32; j++) {
      bit = test_bit(value.bits[i], j);
      if (bit == 1) error = 0;
    }
  }
  return error;
}