#include "tests.h"

START_TEST(TEST_CEIL_1) {
  double x = 0;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_2) {
  double x = -0;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_3) {
  double x = 1;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_4) {
  double x = -1;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_5) {
  double x = 0.1;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_6) {
  double x = -0.1;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_7) {
  double x = 1.1;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_8) {
  double x = -1.1;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_9) {
  double x = 1234.1234;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_10) {
  double x = -1234.1234;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_11) {
  double x = S21_NAN;
  double res_s21 = 0;
  res_s21 = s21_ceil(x);
  ck_assert(isnan(res_s21));
}
END_TEST

START_TEST(TEST_CEIL_12) {
  double x = -S21_NAN;
  double res_s21 = 0;
  res_s21 = s21_ceil(x);
  ck_assert(isnan(res_s21));
}
END_TEST

START_TEST(TEST_CEIL_13) {
  double x = S21_INF;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_14) {
  double x = S21_N_INF;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_15) {
  double x = 0.123456789;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_16) {
  double x = -0.123456789;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_17) {
  double x = 987364589238457.9;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_18) {
  double x = -987364589238457.9;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_19) {
  double x = -1e-23;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_20) {
  double x = (double)LLONG_MAX + 2.1;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_21) {
  double x = (double)LLONG_MIN - 2.1;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

Suite *ceil_suite(void) {
  Suite *s = suite_create("s21_ceil");
  TCase *tc_ceil;

  tc_ceil = tcase_create("TEST_CEIL\n");
  tcase_add_test(tc_ceil, TEST_CEIL_1);
  tcase_add_test(tc_ceil, TEST_CEIL_2);
  tcase_add_test(tc_ceil, TEST_CEIL_3);
  tcase_add_test(tc_ceil, TEST_CEIL_4);
  tcase_add_test(tc_ceil, TEST_CEIL_5);
  tcase_add_test(tc_ceil, TEST_CEIL_6);
  tcase_add_test(tc_ceil, TEST_CEIL_7);
  tcase_add_test(tc_ceil, TEST_CEIL_8);
  tcase_add_test(tc_ceil, TEST_CEIL_9);
  tcase_add_test(tc_ceil, TEST_CEIL_10);
  tcase_add_test(tc_ceil, TEST_CEIL_11);
  tcase_add_test(tc_ceil, TEST_CEIL_12);
  tcase_add_test(tc_ceil, TEST_CEIL_13);
  tcase_add_test(tc_ceil, TEST_CEIL_14);
  tcase_add_test(tc_ceil, TEST_CEIL_15);
  tcase_add_test(tc_ceil, TEST_CEIL_16);
  tcase_add_test(tc_ceil, TEST_CEIL_17);
  tcase_add_test(tc_ceil, TEST_CEIL_18);
  tcase_add_test(tc_ceil, TEST_CEIL_19);
  tcase_add_test(tc_ceil, TEST_CEIL_20);
  tcase_add_test(tc_ceil, TEST_CEIL_21);
  suite_add_tcase(s, tc_ceil);
  return s;
}