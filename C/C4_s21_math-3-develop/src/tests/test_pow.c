#include "tests.h"
/*
** TWO ARGS
*/

#define ASSERT_POW(v1, v2) ck_assert_ldouble_eq_tol(v1, v2, EPSILON);
#define ASSERT_POW_MSG_FMT \
  "ERROR: base:%.7Lf exponent:%.7Lf | s21:%.7Lf f:%.7Lf, equal = %d\n"

static inline void ASSERT_POW_F(long double base, long double exp,
                                int (*f)(double)) {
  long double out21 = s21_pow(base, exp);
  long double out = (long double)pow(base, exp);
  int equal = EQUAL(f(out21), f(out));
  if (!equal) {
    printf(ASSERT_POW_MSG_FMT, base, exp, out21, out, equal);
  }
}

START_TEST(s21_pow_f) {
  ASSERT_POW(s21_pow(2.6, 3.45), pow(2.6, 3.45));
  ASSERT_POW(s21_pow(3.0, 14.0), pow(3.0, 14.0));
  ASSERT_POW(s21_pow(31.456, 4.3), pow(31.456, 4.3));
  ASSERT_POW(s21_pow(31.456, 0.3), pow(31.456, 0.3));
  ASSERT_POW(s21_pow(4.3, 4.3), pow(4.3, 4.3));
  ASSERT_POW(s21_pow(-1234, 4.0), pow(-1234, 4.0));
  ASSERT_POW(s21_pow(1234, -4.3), pow(1234, -4.3));
  ASSERT_POW(s21_pow(0, 1), pow(0, 1));
  ASSERT_POW(s21_pow(0, 2), pow(0, 2));
  ASSERT_POW(s21_pow(-0, 1), pow(-0, 1));
  ASSERT_POW(s21_pow(-0, 2), pow(-0, 2));

  ck_assert_int_eq(__builtin_isinf(s21_pow(0, S21_N_INF)),
                   __builtin_isinf(pow(0, S21_N_INF)));
  ASSERT_POW(s21_pow(-1, S21_N_INF), pow(-1, S21_N_INF));
  ASSERT_POW(s21_pow(-1, S21_INF), pow(-1, S21_INF));
}
END_TEST

#define TEST(name, v1, v2)                 \
  START_TEST(name) { ASSERT_POW(v1, v2); } \
  END_TEST
#define TEST_F(name, v1, v2, f)                 \
  START_TEST(name) { ASSERT_POW_F(v1, v2, f); } \
  END_TEST

TEST(zero_zero, 0, 0);
START_TEST(one__zero) {
  long double base = 1;
  long double exp = 0;
  ck_assert_double_eq(pow(base, exp), s21_pow(base, exp));
}

TEST_F(zero_nan, 0, S21_NAN, __builtin_isnan);
TEST_F(zero_nnan, 0, S21_N_NAN, __builtin_isnan);
TEST_F(zero_inf, 0, S21_INF, __builtin_isinf);
TEST_F(zero_ninf_returns_inf, 0, S21_N_INF, __builtin_isinf);
TEST_F(minus_one__inf, -1, S21_INF, __builtin_isinf);
TEST_F(minus_one__ninf, -1, S21_N_INF, __builtin_isinf);
TEST_F(minus_one__nan, -1, S21_NAN, __builtin_isinf);
TEST_F(minus_one__nnan, -1, S21_N_NAN, __builtin_isinf);
START_TEST(one__inf) {
  long double base = 1;
  long double exp = S21_INF;
  ck_assert_double_eq(s21_pow(base, exp), pow(base, exp));
}
TEST_F(one__ninf, 1, S21_N_INF, __builtin_isinf)
START_TEST(one__nan) {
  long double base = 1;
  long double exp = S21_N_NAN;
  ck_assert_double_eq(s21_pow(base, exp), pow(base, exp));
}
START_TEST(one__nnan) {
  long double base = 1;
  long double exp = S21_N_NAN;
  ck_assert_double_eq(s21_pow(base, exp), pow(base, exp));
}
TEST_F(nan__zero, S21_NAN, 0, __builtin_isnan)
TEST_F(nnan__zero, S21_N_NAN, 0, __builtin_isnan)
START_TEST(inf__zero) {
  long double base = S21_INF;
  long double exp = 0;
  ck_assert_double_eq(s21_pow(base, exp), pow(base, exp));
}
START_TEST(ninf__zero) {
  long double base = S21_N_INF;
  long double exp = 0;
  ck_assert_double_eq(s21_pow(base, exp), pow(base, exp));
}
TEST_F(less_one__inf, 0.1, S21_INF, __builtin_isnan)
TEST_F(less_one__ninf, 0.1, S21_N_INF, __builtin_isinf)

TEST_F(all_neg, -10.1261, -0.72, __builtin_isnan)
TEST_F(zero_exp_neg, 0, -0.72, __builtin_isinf)
TEST_F(neg_zero_exp_neg, -0, -0.72, __builtin_isinf)
START_TEST(neg_zero_inf) {
  long double base = -0;
  long double exp = S21_INF;
  ck_assert_double_eq(s21_pow(base, exp), pow(base, exp));
}
TEST_F(zero_neg_nan, -0, S21_NAN, __builtin_isnan);
TEST_F(zero_neg_nnan, -0, S21_N_NAN, __builtin_isnan);

START_TEST(less_than_one_minus_inf) {
  long double base = 0.5591951;
  long double exp = -S21_INF;
  ck_assert_ldouble_infinite(pow(base, exp));
  ck_assert_ldouble_infinite(s21_pow(base, exp));
}
END_TEST

START_TEST(base_gt_one_minus_inf) {
  long double base = 1.5591951;
  long double exp = -S21_INF;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), EPSILON);
}
END_TEST

START_TEST(base_less_one_plus_inf) {
  long double base = 0.5591951;
  long double exp = S21_INF;
  ck_assert_int_eq(__builtin_isinf(s21_pow(base, exp)),
                   __builtin_isinf(pow(base, exp)));
}
END_TEST

START_TEST(gt_one_plus_inf) {
  long double base = 1.5591951;
  long double exp = S21_INF;
  ck_assert_int_eq(__builtin_isinf(s21_pow(base, exp)),
                   __builtin_isinf(pow(base, exp)));
}
END_TEST

START_TEST(minus_inf_neg_odd) {
  long double base = -S21_INF;
  long double exp = -193491;
  ck_assert_int_eq(__builtin_isinf(s21_pow(base, exp)),
                   __builtin_isinf(pow(base, exp)));
}
END_TEST

START_TEST(minus_inf_neg_int_even) {
  long double base = -S21_INF;
  long double exp = -142;
  ck_assert_double_eq(s21_pow(base, exp), pow(base, exp));
}
END_TEST

START_TEST(m_inf_positive_odd) {
  long double base = -S21_INF;
  long double exp = S21_INF;
  ck_assert_int_eq(__builtin_isinf(s21_pow(base, exp)),
                   __builtin_isinf(pow(base, exp)));
}
END_TEST

START_TEST(m_inf_positive_even) {
  long double base = -S21_INF;
  long double exp = 142;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(inf_neg) {
  long double base = S21_INF;
  long double exp = -2;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), EPSILON);
}
END_TEST

START_TEST(inf_pos) {
  long double base = S21_INF;
  long double exp = 1;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

Suite *pow_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_pow tests:");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_pow_f);
  tcase_add_test(tc_core, zero_zero);
  tcase_add_test(tc_core, zero_nan);
  tcase_add_test(tc_core, zero_nnan);
  tcase_add_test(tc_core, zero_inf);
  tcase_add_test(tc_core, zero_ninf_returns_inf);
  tcase_add_test(tc_core, minus_one__inf);
  tcase_add_test(tc_core, minus_one__ninf);
  tcase_add_test(tc_core, one__zero);

  tcase_add_test(tc_core, one__inf);
  tcase_add_test(tc_core, one__ninf);
  tcase_add_test(tc_core, one__nan);
  tcase_add_test(tc_core, one__nnan);
  tcase_add_test(tc_core, nan__zero);
  tcase_add_test(tc_core, nnan__zero);
  tcase_add_test(tc_core, inf__zero);
  tcase_add_test(tc_core, ninf__zero);
  tcase_add_test(tc_core, less_one__inf);
  tcase_add_test(tc_core, less_one__ninf);
  tcase_add_test(tc_core, minus_one__nan);
  tcase_add_test(tc_core, minus_one__nnan);
  tcase_add_test(tc_core, less_one__ninf);
  tcase_add_test(tc_core, all_neg);
  tcase_add_test(tc_core, inf_pos);
  tcase_add_test(tc_core, inf_neg);
  tcase_add_test(tc_core, m_inf_positive_even);
  tcase_add_test(tc_core, m_inf_positive_odd);
  tcase_add_test(tc_core, minus_inf_neg_int_even);
  tcase_add_test(tc_core, minus_inf_neg_odd);
  tcase_add_test(tc_core, gt_one_plus_inf);
  tcase_add_test(tc_core, base_less_one_plus_inf);
  tcase_add_test(tc_core, base_gt_one_minus_inf);
  tcase_add_test(tc_core, less_than_one_minus_inf);
  tcase_add_test(tc_core, zero_neg_nnan);
  tcase_add_test(tc_core, zero_neg_nan);
  tcase_add_test(tc_core, neg_zero_inf);
  tcase_add_test(tc_core, neg_zero_exp_neg);
  tcase_add_test(tc_core, zero_exp_neg);

  suite_add_tcase(s, tc_core);
  return s;
}