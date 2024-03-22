#include "tests.h"

START_TEST(TEST_FLOOR_1) {
  double x = 0;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_floor(x);
  res = floor(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_FLOOR_2) {
  double x = -0;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_floor(x);
  res = floor(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_FLOOR_3) {
  double x = 1;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_floor(x);
  res = floor(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_FLOOR_4) {
  double x = -1;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_floor(x);
  res = floor(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_FLOOR_5) {
  double x = 0.1;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_floor(x);
  res = floor(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_FLOOR_6) {
  double x = -0.1;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_floor(x);
  res = floor(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_FLOOR_7) {
  double x = 1.1;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_floor(x);
  res = floor(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_FLOOR_8) {
  double x = -1.1;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_floor(x);
  res = floor(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_FLOOR_9) {
  double x = 1234.1234;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_floor(x);
  res = floor(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_FLOOR_10) {
  double x = -1234.1234;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_floor(x);
  res = floor(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_FLOOR_11) {
  double x = S21_NAN;
  double res_s21 = 0;
  res_s21 = s21_floor(x);
  ck_assert(isnan(res_s21));
}
END_TEST

START_TEST(TEST_FLOOR_12) {
  double x = -S21_NAN;
  double res_s21 = 0;
  res_s21 = s21_floor(x);
  ck_assert(isnan(res_s21));
}
END_TEST

START_TEST(TEST_FLOOR_13) {
  double x = S21_INF;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_floor(x);
  res = floor(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_FLOOR_14) {
  double x = S21_N_INF;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_floor(x);
  res = floor(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_FLOOR_15) {
  double x = 0.123456789;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_floor(x);
  res = floor(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_FLOOR_16) {
  double x = -0.123456789;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_floor(x);
  res = floor(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_FLOOR_17) {
  double x = 987364589238457.9;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_floor(x);
  res = floor(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_FLOOR_18) {
  double x = -987364589238457.9;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_floor(x);
  res = floor(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_FLOOR_19) {
  double x = (double)LLONG_MAX + 2.1;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_floor(x);
  res = floor(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_FLOOR_20) {
  double x = (double)LLONG_MIN - 2.1;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_floor(x);
  res = floor(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

Suite *floor_suite(void) {
  Suite *s = suite_create("s21_floor");
  TCase *tc_floor;

  tc_floor = tcase_create("TEST_FLOOR\n");
  tcase_add_test(tc_floor, TEST_FLOOR_1);
  tcase_add_test(tc_floor, TEST_FLOOR_2);
  tcase_add_test(tc_floor, TEST_FLOOR_3);
  tcase_add_test(tc_floor, TEST_FLOOR_4);
  tcase_add_test(tc_floor, TEST_FLOOR_5);
  tcase_add_test(tc_floor, TEST_FLOOR_6);
  tcase_add_test(tc_floor, TEST_FLOOR_7);
  tcase_add_test(tc_floor, TEST_FLOOR_8);
  tcase_add_test(tc_floor, TEST_FLOOR_9);
  tcase_add_test(tc_floor, TEST_FLOOR_10);
  tcase_add_test(tc_floor, TEST_FLOOR_11);
  tcase_add_test(tc_floor, TEST_FLOOR_12);
  tcase_add_test(tc_floor, TEST_FLOOR_13);
  tcase_add_test(tc_floor, TEST_FLOOR_14);
  tcase_add_test(tc_floor, TEST_FLOOR_15);
  tcase_add_test(tc_floor, TEST_FLOOR_16);
  tcase_add_test(tc_floor, TEST_FLOOR_17);
  tcase_add_test(tc_floor, TEST_FLOOR_18);
  tcase_add_test(tc_floor, TEST_FLOOR_19);
  tcase_add_test(tc_floor, TEST_FLOOR_20);
  suite_add_tcase(s, tc_floor);
  return s;
}