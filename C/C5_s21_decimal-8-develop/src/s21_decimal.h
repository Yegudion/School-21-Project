#ifndef S21_DECIMAL
#define S21_DECIMAL

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_255 255

#define DEC_MAX 4294967296
#define S21_MAX_UINT 4294967295
/* unsigned int bits[4] = {0, 0, 0, 0}
   bit[0] - num sec; bit[1] - num sec; bit[2] - num sec;

   bit[3] - dec info; 0-15 bits are zero; 16-23 bits are scale factor;
   24-30 bits are zero; 31 is sign bit.
   [s0000000ffffffff0000000000000000]: s - sign; f - scale factor;
*/

typedef struct s21_decimal {
  unsigned int bits[4];
} s21_decimal;

typedef enum s_result {
  RESULT_OK,
  RESULT_TOO_LAGRE,
  RESULT_TOO_SMALL,
  RESULT_DIV_BY_ZERO
} e_result;

// Arithmetics!

// Decimal addicion operator (+)
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_add2(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
// Decimal substraction operator (-)
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
// Decimal multiplication operator (*)
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
// Decimal division operator (/)
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
/* return error codes:
    0 - OK
    1 - the number is too large or equal to infinity
    2 - the number is too small or equal to negative infinity
    3 - division by 0
*/

// Comparsion!

// Decimal less_than operator (<)
int s21_is_less(s21_decimal op_1, s21_decimal op_2);
// Decimal less_than_or_equal_to operator (<=)
int s21_is_less_or_equal(s21_decimal op_1, s21_decimal op_2);
// Decimal greater_than operator (>)
int s21_is_greater(s21_decimal op_1, s21_decimal op_2);
// Decimal greater_than_or_equal_to operator (>=)
int s21_is_greater_or_equal(s21_decimal op_1, s21_decimal op_2);
// Decimal equal_to operator (==)
int s21_is_equal(s21_decimal op_1, s21_decimal op_2);
// Decimal not_equal_to operator (!=)
int s21_is_not_equal(s21_decimal op_1, s21_decimal op_2);
/* Return values:
    0 - FALSE
    1 - TRUE
*/

// Convertors and parsers!

// Decimal from int (int -> dec)
int s21_from_int_to_decimal(int src, s21_decimal *dst);
// Decimal from float (float -> dec)
int s21_from_float_to_decimal(float src, s21_decimal *dst);
// Decimal to int (dec -> int)
int s21_from_decimal_to_int(s21_decimal src, int *dst);
// Decimal to float (dec -> float)
int s21_from_decimal_to_float(s21_decimal src, float *dst);
/* Return error codes:
    0 - OK
    1 - convertation error
*/

// Another S21 functions!

// Round DOWN value (3,16 -> 3,1; 3,14 ->3,1)
int s21_floor(s21_decimal value, s21_decimal *result);
// Round UP value (3,16 -> 3,2; 3,14 -> 3,1)
int s21_round(s21_decimal value, s21_decimal *result);
// Cut off fraction (3,14 -> 3)
int s21_truncate(s21_decimal value, s21_decimal *result);
// Multiply by "-1" (3,14 -> -3,14 || -3,14 -> 3,14)
int s21_negate(s21_decimal value, s21_decimal *result);
/* Return error codes:
    0 - OK
    1 - calculation error
*/

// Additional functions!

/* Sets decimal variable
   sign - decimal sign: 0 - positive, 1 - negative;
   scale_factor - decimal scale factor with possible values between 28 and 0
   (including);
   bit2 - sets dec.bits[2];
   bit1 - sets dec.bits[1];
   bit0 - sets dec.bits[0];

   If sign or scale are incorrect - returns zero decimal {0,0,0,0,0}.
*/
s21_decimal s21_create(int sign, int scale_factor, unsigned int bit2,
                       unsigned int bit1, unsigned int bit0);
// Get sign value of decimal (0 - positive; 1 - negative)
int s21_get_dec_sign(s21_decimal value, int *result);
// Get scale factor of decimal
int s21_get_dec_scale_factor(s21_decimal value, int *result);
// Set sign value of decimal (0 - positive; 1 - negative)
int s21_set_dec_sign(s21_decimal *result, int value);
// Set scale factor of decimal
int s21_set_dec_scale_factor(s21_decimal *result, int value);
// Greater if scale factors are equal
int s21_is_greater(s21_decimal op_1, s21_decimal op_2);
// If both factors are equal
// int sub_greater(s21_decimal const *const op_1, s21_decimal const *const op_2,
//                 int const sign);
// // If factor of op_1 less than 9
// int fac_l_9(s21_decimal const op_1, s21_decimal const op_2,
//             int const factor_op_1, int const factor_op_2, int const sign);
// // If factor of op_1 less than 18
// int fac_l_18(s21_decimal const op_1, s21_decimal const op_2,
//              int const factor_op_1, int const factor_op_2, int const sign);
// // If factor of op_1 less else
// int fac_l_e(s21_decimal const op_1, s21_decimal const op_2,
//             int const factor_op_1, int const factor_op_2, int const sign);

s21_decimal *set_single_bit(s21_decimal *const mutable_val,
                            int const bit_number, int const new_bit_val);
void cast_to_same_scale(s21_decimal *decimal1, s21_decimal *decimal2);
int scan_single_bit(s21_decimal const scaned_val,
                    int const bit_position_number);

// void printBits(unsigned int value);

int s21_mult_ten(s21_decimal *value);
void s21_bit_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

void dec_left_shift(s21_decimal *result, int shift);

/* Return error codes:
    0 - OK
    1 - error
*/

// helpers
int test_bit(unsigned int value, int BitNumber);
int s21_shift(s21_decimal *number);
int s21_addiction_logic(s21_decimal value_1, s21_decimal value_2,
                        s21_decimal *result);
int s21_10_conv(s21_decimal value);
void set_1_bit(unsigned int *value, int BitNumber);

void set_0_bit(unsigned int *value, int BitNumber);
void s21_rev_10_conv(s21_decimal *value, int result);
void s21_unshift(s21_decimal *number);

int s21_zero(s21_decimal value);

#endif