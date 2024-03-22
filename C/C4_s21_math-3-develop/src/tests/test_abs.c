#include "tests.h"

static inline void ASSERT_ABS(int value) {
  ck_assert_int_eq(s21_abs(value), abs(value));
}

START_TEST(test_s21_math_abs_usual) {
  ASSERT_ABS(INT_MAX);
  ASSERT_ABS(INT_MIN);
}
END_TEST

Suite *s21_math_abs_suite(void) {
  Suite *s;
  TCase *tc_abs_usual, *tc_abs_unusual;

  s = suite_create("s21_abs");

  tc_abs_usual = tcase_create("s21_abs_usual");
  tcase_add_test(tc_abs_usual, test_s21_math_abs_usual);

  return s;
}