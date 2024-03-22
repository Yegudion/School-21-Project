#include "s21_test.h"

// add function
START_TEST(add_2) {
  // Maximum positive number + maximum positive number -> error, too large
  s21_decimal first = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal second = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int status = 0;
  status = s21_add(first, second, &result);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(add_3) {
  // Maximum negative number + Maximum negative number -> error, too small
  s21_decimal first = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, SIGN_MASK}};
  s21_decimal second = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, SIGN_MASK}};
  s21_decimal result = {{0, 0, 0, 0}};
  int status = s21_add(first, second, &result);
  ck_assert_int_eq(status, 2);
}
END_TEST

START_TEST(s21_add_test_1) {  // 2 + 3 = 5
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_decimal result = {0};
  s21_decimal check = {{5, 0, 0, 0}};
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_2) {  // -2 + 3 = 1
  s21_decimal value_1 = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_decimal result = {0};
  s21_decimal check = {{1, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_3) {  // 2 + (-3) = -1
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{1, 0, 0, 0b10000000000000000000000000000000}};
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_4) {  // -2 + (-3) = -5
  s21_decimal value_1 = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{5, 0, 0, 0b10000000000000000000000000000000}};
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_5) {  // -5 + 3 = -2
  s21_decimal value_1 = {{5, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{2, 0, 0, 0b10000000000000000000000000000000}};
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_6) {  // 5 + (-3) = 2
  s21_decimal value_1 = {{5, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{2, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_7) {  // 3.33 + 3.3 = 6.63
  s21_decimal value_1 = {{333, 0, 0, 0b0000000000000000000000000000000}};
  s21_set_dec_scale_factor(&value_1, 2);
  s21_decimal value_2 = {{33, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_dec_scale_factor(&value_2, 1);
  s21_decimal result = {0};
  s21_decimal check = {{663, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_dec_scale_factor(&check, 2);
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_8) {  // 1.78 + 12.80 = 6.63
  s21_decimal value_1 = {{178, 0, 0, 0b0000000000000000000000000000000}};
  s21_set_dec_scale_factor(&value_1, 2);
  s21_decimal value_2 = {{1280, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_dec_scale_factor(&value_2, 2);
  s21_decimal result = {0};
  s21_decimal check = {{1458, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_dec_scale_factor(&check, 2);
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_9) {  // 0.12 + 123 = 123.12
  s21_decimal value_1 = {{12, 0, 0, 0b0000000000000000000000000000000}};
  s21_set_dec_scale_factor(&value_1, 2);
  s21_decimal value_2 = {{123, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{12312, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_dec_scale_factor(&check, 2);
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_10) {  // -0.017 + 0.0004 = -0.0166
  s21_decimal value_1 = {{17, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_dec_scale_factor(&value_1, 3);
  s21_decimal value_2 = {{4, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_dec_scale_factor(&value_2, 4);
  s21_decimal result = {0};
  s21_decimal check = {{166, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_dec_scale_factor(&check, 4);
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);

  // int check_sign=0;
  // s21_get_dec_scale_factor(result, &check_sign);
  // printf("check scale : %d\n", check_sign);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_11) {  // 0.000001 + (-0.000001) = 0.000000
  s21_decimal value_1 = {{1, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_dec_scale_factor(&value_1, 6);
  s21_decimal value_2 = {{1, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_dec_scale_factor(&value_2, 6);
  s21_decimal result = {0};
  s21_decimal check = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_dec_scale_factor(&check, 6);
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_12) {  // 2 + (-2) = 0
  s21_decimal value_1 = {{2, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal value_2 = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{0, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_13) {  // -2 + 2 = 0
  s21_decimal value_1 = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{2, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{0, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_14) {  // -0.000001 + 0.000001 = 0.000000
  s21_decimal value_1 = {{1, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_dec_scale_factor(&value_1, 6);
  s21_decimal value_2 = {{1, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_dec_scale_factor(&value_2, 6);
  s21_decimal result = {0};
  s21_decimal check = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_dec_scale_factor(&check, 6);
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(
    s21_add_test_15) {  // 79228162514264337593543950335 + 5 = overflow!!!
  s21_decimal value_1 = {
      {4294967295, 4294967295, 4294967295, 0b00000000000000000000000000000000}};
  s21_set_dec_scale_factor(&value_1, 0);
  s21_decimal value_2 = {{5, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_dec_scale_factor(&value_2, 0);
  s21_decimal result = {0};
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 1);
}
END_TEST

START_TEST(s21_add_test_16) {  // 0.49999 + 0.00001 = 0.50000
  s21_decimal value_1 = {{0x7a11f, 0, 0, 0x60000}};
  s21_decimal value_2 = {{0x1, 0, 0, 0x60000}};
  s21_decimal result = {0};
  s21_decimal check = {{0x7a120, 0, 0, 0x60000}};
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_17) {  // -46551.2345 + 1452.1212
  s21_decimal value_1 = {{465512345, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_dec_scale_factor(&value_1, 4);
  s21_decimal value_2 = {{14521212, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_dec_scale_factor(&value_2, 4);
  s21_decimal result = {0};
  s21_decimal check = {{450991133, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_dec_scale_factor(&check, 4);
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_18) {
  s21_decimal value_1 = {{24, 1, 1, -2147418112}};
  s21_decimal value_2 = {{1, 15, 1, 655360}};
  s21_decimal result = {0};
  s21_decimal check = {{0x9682efff, 0x3b9ac9f6, 0x3b9ac9ff, 0x800a0000}};
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

// sub function
START_TEST(s21_sub_test_1) {  // 2 - 3 = -1
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_decimal result = {0};
  s21_decimal check = {{1, 0, 0, 0b10000000000000000000000000000000}};
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_sub_test_2) {  // -2 - 3 = -5
  s21_decimal value_1 = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_decimal result = {0};
  s21_decimal check = {{5, 0, 0, 0b10000000000000000000000000000000}};
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_sub_test_3) {  // 2 - (-3) = 5
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{5, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_sub_test_4) {  // -2 - (-3) = 1
  s21_decimal value_1 = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{1, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_sub_test_5) {  // -5 - 3 = -8
  s21_decimal value_1 = {{5, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{8, 0, 0, 0b10000000000000000000000000000000}};
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_sub_test_6) {  // 5 - (-3) = 8
  s21_decimal value_1 = {{5, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{8, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_sub_test_7) {  // 3.33 - 3.3 = 0.03
  s21_decimal value_1 = {{333, 0, 0, 0b0000000000000000000000000000000}};
  s21_set_dec_scale_factor(&value_1, 2);
  s21_decimal value_2 = {{33, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_dec_scale_factor(&value_2, 1);
  s21_decimal result = {0};
  s21_decimal check = {{3, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_dec_scale_factor(&check, 2);

  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);

  // int sign;
  // s21_get_dec_sign(check, &sign);

  // int scale;
  // s21_get_dec_scale_factor(check, &scale);

  // printf("\ncheck sign: %d, check scale: %d\n", sign, scale);

  //   int signR;
  // s21_get_dec_sign(result, &signR);

  // int scaleR;
  // s21_get_dec_scale_factor(result, &scaleR);

  // printf("\ncheck sign: %d, check scale: %d\n", signR, scaleR);

  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_sub_test_8) {  // 1.78 - 12.80 = -11.02
  s21_decimal value_1 = {{178, 0, 0, 0b0000000000000000000000000000000}};
  s21_set_dec_scale_factor(&value_1, 2);
  s21_decimal value_2 = {{1280, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_dec_scale_factor(&value_2, 2);
  s21_decimal result = {0};
  s21_decimal check = {{1102, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_dec_scale_factor(&check, 2);
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_sub_test_9) {  // 0.12 - 123 = -122.88
  s21_decimal value_1 = {{12, 0, 0, 0b0000000000000000000000000000000}};
  s21_set_dec_scale_factor(&value_1, 2);
  s21_decimal value_2 = {{123, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{12288, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_dec_scale_factor(&check, 2);
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_sub_test_10) {  // -0.017 - 0.0004 = -0.0174
  s21_decimal value_1 = {{17, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_dec_scale_factor(&value_1, 3);
  s21_decimal value_2 = {{4, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_dec_scale_factor(&value_2, 4);
  s21_decimal result = {0};
  s21_decimal check = {{174, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_dec_scale_factor(&check, 4);
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);

  // int scale1, scale2;
  // s21_get_dec_sign(result, &scale1);
  // s21_get_dec_scale_factor(value_2, &scale2);

  // printf("\result= %d\n", scale1);
  // printf("scale_2= %d\n", scale2);

  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_sub_test_11) {  // -0.000001 - (-0.000001) = 0.000000
  s21_decimal value_1 = {{1, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_dec_scale_factor(&value_1, 6);
  s21_decimal value_2 = {{1, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_dec_scale_factor(&value_2, 6);
  s21_decimal result = {0};
  s21_decimal check = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_dec_scale_factor(&check, 6);
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_sub_test_12) {  // -2 - (-2) = 0
  s21_decimal value_1 = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{0, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_sub_test_13) {  // 2 - 2 = 0
  s21_decimal value_1 = {{2, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal value_2 = {{2, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{0, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_sub_test_14) {  // -12133.512 - 11321.21103 = -23454.72303
  s21_decimal value_1 = {{12133512, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_dec_scale_factor(&value_1, 3);
  s21_decimal value_2 = {
      {1132121103, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_dec_scale_factor(&value_2, 5);
  s21_decimal result = {0};
  s21_decimal check = {{2345472303, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_dec_scale_factor(&check, 5);
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

// mul function
START_TEST(mul_test_1) {
  int num1 = -10;
  int num2 = -10;
  int prod_int = 100;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, prod_int);
}
END_TEST

START_TEST(mul_test_2) {
  int num1 = 10;
  int num2 = 20;
  int prod_int = 200;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, prod_int);
}
END_TEST

START_TEST(mul_test_3) {
  int num1 = -10;
  int num2 = 20;
  int prod_int = -200;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, prod_int);
}
END_TEST

START_TEST(mul_test_4) {
  int num1 = 9403;
  int num2 = 202;
  int res_origin = 1899406;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(mul_test_5) {
  int num1 = -32768;
  int num2 = 2;
  int res_origin = -65536;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(mul_test_6) {
  int num1 = -32768;
  int num2 = 32768;
  int res_origin = -1073741824;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(mul_test_7) {
  float num1 = 9403.0e2;
  int num2 = 202;
  float res_origin = 189940600;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(s21_div_test_1) {  // -6 : 3 = 0 # !!!!
  s21_decimal value_1 = {{6, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_decimal result = {{0}};
  s21_decimal check = {{0}};
  ck_assert_int_eq((s21_div(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_div_test_2) {  // -6 : 0 = error
  s21_decimal value_1 = {{6, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{0}};
  s21_decimal result = {{0}};
  int res = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(res, RESULT_DIV_BY_ZERO);
}
END_TEST

// START_TEST(s21_div_test_3) {  // 6 : (-3) = -2
//   s21_decimal value_1 = {{6, 0, 0, 0}};
//   s21_decimal value_2 = {{3, 0, 0, 0b10000000000000000000000000000000}};
//   s21_decimal result = {0};
//   s21_decimal check = {{2, 0, 0, 0b10000000000000000000000000000000}};
//   ck_assert_int_eq((s21_div(value_1, value_2, &result)), 0);
//   ck_assert_int_eq(result.bits[0], check.bits[0]);
//   ck_assert_int_eq(result.bits[1], check.bits[1]);
//   ck_assert_int_eq(result.bits[2], check.bits[2]);
//   ck_assert_int_eq(result.bits[3], check.bits[3]);
// }
// END_TEST

// START_TEST(s21_div_test_4) {  // -6 : (-3) = 2
//   s21_decimal value_1 = {{6, 0, 0, 0b10000000000000000000000000000000}};
//   s21_decimal value_2 = {{3, 0, 0, 0b10000000000000000000000000000000}};
//   s21_decimal result = {0};
//   s21_decimal check = {{2, 0, 0, 0b00000000000000000000000000000000}};
//   ck_assert_int_eq((s21_div(value_1, value_2, &result)), 0);
//   ck_assert_int_eq(result.bits[0], check.bits[0]);
//   ck_assert_int_eq(result.bits[1], check.bits[1]);
//   ck_assert_int_eq(result.bits[2], check.bits[2]);
//   ck_assert_int_eq(result.bits[3], check.bits[3]);
// }
// END_TEST

// START_TEST(s21_div_test_5) {  // -15 : 3 = -5
//   s21_decimal value_1 = {{15, 0, 0, 0b10000000000000000000000000000000}};
//   s21_decimal value_2 = {{3, 0, 0, 0b00000000000000000000000000000000}};
//   s21_decimal result = {0};
//   s21_decimal check = {{5, 0, 0, 0b10000000000000000000000000000000}};
//   ck_assert_int_eq((s21_div(value_1, value_2, &result)), 0);
//   ck_assert_int_eq(result.bits[0], check.bits[0]);
//   ck_assert_int_eq(result.bits[1], check.bits[1]);
//   ck_assert_int_eq(result.bits[2], check.bits[2]);
//   ck_assert_int_eq(result.bits[3], check.bits[3]);
// }
// END_TEST

// START_TEST(s21_div_test_6) {  // -15 : (-3) = 5
//   s21_decimal value_1 = {{15, 0, 0, 0b10000000000000000000000000000000}};
//   s21_decimal value_2 = {{3, 0, 0, 0b10000000000000000000000000000000}};
//   s21_decimal result = {0};
//   s21_decimal check = {{5, 0, 0, 0b00000000000000000000000000000000}};
//   ck_assert_int_eq((s21_div(value_1, value_2, &result)), 0);
//   ck_assert_int_eq(result.bits[0], check.bits[0]);
//   ck_assert_int_eq(result.bits[1], check.bits[1]);
//   ck_assert_int_eq(result.bits[2], check.bits[2]);
//   ck_assert_int_eq(result.bits[3], check.bits[3]);
// }
// END_TEST

// START_TEST(s21_div_test_7) {  // 79228162514264337593543950335 : 0 = DIV
// ZERO
//   s21_decimal value_1 = {
//       {4294967295, 4294967295, 4294967295,
//       0b00000000000000000000000000000000}};
//   s21_decimal value_2 = {{0, 0, 0, 0b00000000000000000000000000000000}};
//   s21_decimal result = {0};
//   ck_assert_int_eq((s21_div(value_1, value_2, &result)), 3);
// }
// END_TEST

// START_TEST(
//     s21_div_test_8) {  // 79228162514264337593543950335 : -0.0000 = DIVZERO
//   s21_decimal value_1 = {
//       {4294967295, 4294967295, 4294967295,
//       0b00000000000000000000000000000000}};
//   s21_decimal value_2 = {{0, 0, 0, 0x80040000}};
//   s21_decimal result = {0};
//   ck_assert_int_eq((s21_div(value_1, value_2, &result)), 3);
// }
// END_TEST

void add_add_tests(TCase *tc_math) {
  // add func
  tcase_add_test(tc_math, add_2);
  tcase_add_test(tc_math, add_3);
  tcase_add_test(tc_math, s21_add_test_1);
  tcase_add_test(tc_math, s21_add_test_2);
  tcase_add_test(tc_math, s21_add_test_3);
  tcase_add_test(tc_math, s21_add_test_4);
  tcase_add_test(tc_math, s21_add_test_5);
  tcase_add_test(tc_math, s21_add_test_6);
  tcase_add_test(tc_math, s21_add_test_7);
  tcase_add_test(tc_math, s21_add_test_8);
  tcase_add_test(tc_math, s21_add_test_9);
  tcase_add_test(tc_math, s21_add_test_10);
  tcase_add_test(tc_math, s21_add_test_11);
  tcase_add_test(tc_math, s21_add_test_12);
  tcase_add_test(tc_math, s21_add_test_13);
  tcase_add_test(tc_math, s21_add_test_14);
  tcase_add_test(tc_math, s21_add_test_15);
  tcase_add_test(tc_math, s21_add_test_16);
  tcase_add_test(tc_math, s21_add_test_17);
  tcase_add_test(tc_math, s21_add_test_18);
}

void add_sub_tests(TCase *tc_math) {
  // sub func
  tcase_add_test(tc_math, s21_sub_test_1);
  tcase_add_test(tc_math, s21_sub_test_2);
  tcase_add_test(tc_math, s21_sub_test_3);
  tcase_add_test(tc_math, s21_sub_test_4);
  tcase_add_test(tc_math, s21_sub_test_5);
  tcase_add_test(tc_math, s21_sub_test_6);
  tcase_add_test(tc_math, s21_sub_test_7);
  tcase_add_test(tc_math, s21_sub_test_8);
  tcase_add_test(tc_math, s21_sub_test_9);
  tcase_add_test(tc_math, s21_sub_test_10);
  tcase_add_test(tc_math, s21_sub_test_11);
  tcase_add_test(tc_math, s21_sub_test_12);
  tcase_add_test(tc_math, s21_sub_test_13);
  tcase_add_test(tc_math, s21_sub_test_14);
}

void add_mul_tests(TCase *tc_math) {
  // mul func
  tcase_add_test(tc_math, mul_test_1);
  tcase_add_test(tc_math, mul_test_2);
  tcase_add_test(tc_math, mul_test_3);
  tcase_add_test(tc_math, mul_test_4);
  tcase_add_test(tc_math, mul_test_5);
  tcase_add_test(tc_math, mul_test_6);
  tcase_add_test(tc_math, mul_test_7);
}

void add_div_tests(TCase *tc_math) {
  tcase_add_test(tc_math, s21_div_test_1);
  tcase_add_test(tc_math, s21_div_test_2);
}

void srunner_add_math_tests(SRunner *sr) {
  Suite *save_v1 = suite_create("Math");
  TCase *tc_math = tcase_create("Math");
  suite_add_tcase(save_v1, tc_math);

  add_add_tests(tc_math);
  add_sub_tests(tc_math);
  add_mul_tests(tc_math);
  add_div_tests(tc_math);

  srunner_add_suite(sr, save_v1);
}