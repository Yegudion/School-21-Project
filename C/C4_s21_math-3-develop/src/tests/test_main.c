#include "tests.h"

//#define ASSERT(f21, f, value) ck_assert_ldouble_eq_tol(f21(value), (long
// double)(f(value)), EPSILON)

static inline void assert_args(double *args, int args_size,
                               long double (*f21)(double),
                               double (*f)(double)) {
  for (int i = 0; i < args_size; i++) {
    ASSERT(f21, f, args[i]);
  }
}

START_TEST(s21_ceil_f) {
  double args[] = {1.5, 0.45, -3.01, -0, 1234567};
  assert_args(args, LEN_ARR(args), s21_ceil, ceil);
}
END_TEST

START_TEST(s21_floor_f) {
  double args[] = {1.5, 0.45, -3.01, -0, 1234567};
  assert_args(args, LEN_ARR(args), s21_floor, floor);
}
END_TEST

static inline void assert_trigonometry(long double (*f21)(double),
                                       double (*f)(double)) {
  for (double i = -100; i < 100; i += 2) {
    ASSERT(f21, f, i);
  }
  for (double i = M_PI * 1; i <= M_PI; i += 0.01) {
    ASSERT(f21, f, i);
  }
}

static inline void assert_trigonometry_arc(long double (*f21)(double),
                                           double (*f)(double)) {
  for (double i = -1; i <= 1; i += 0.01) {
    ASSERT(f21, f, i);
  }
}

START_TEST(s21_tan_f) { assert_trigonometry(s21_tan, tan); }
END_TEST

START_TEST(s21_cos_f) { assert_trigonometry(s21_cos, cos); }
END_TEST

START_TEST(s21_sin_f) { assert_trigonometry(s21_sin, sin); }
END_TEST

START_TEST(s21_atan_f) { assert_trigonometry_arc(s21_atan, atan); }
END_TEST

START_TEST(s21_acos_f) { assert_trigonometry_arc(s21_acos, acos); }
END_TEST

START_TEST(s21_asin_f) { assert_trigonometry_arc(s21_asin, asin); }
END_TEST

START_TEST(s21_fmod_f) {
  ck_assert_ldouble_eq_tol(s21_fmod(456.87678, 3.7), fmod(456.87678, 3.7),
                           EPSILON);
  ck_assert_ldouble_eq_tol(s21_fmod(36677.546546, 4.1), fmod(36677.546546, 4.1),
                           EPSILON);
  ck_assert_ldouble_eq_tol(s21_fmod(23.456, 4.355), fmod(23.456, 4.355),
                           EPSILON);
}
END_TEST

START_TEST(s21_exp_f) {
  ASSERT(s21_exp, exp, 5.);
  ASSERT(s21_exp, exp, -2.);
  ASSERT(s21_exp, exp, -1234567.);
  for (double i = -10; i < 10; i++) {
    ASSERT(s21_exp, exp, i);
  }
}
END_TEST

START_TEST(s21_log_f) {
  ASSERT(s21_log, log, 12356);
  ASSERT(s21_log, log, 1.1);
  for (double i = 0.1; i < 10; i += 0.1) {
    ASSERT(s21_log, log, i);
  }
  for (double i = 0.1; i < 2; i += 0.01) {
    ASSERT(s21_log, log, i);
  }
}
END_TEST

START_TEST(s21_sqrt_f) {
  double args[] = {16.0, 45.43, 5., 0};
  ASSERT_ARGS(s21_sqrt, sqrt);

  for (double i = 0; i < 100000; i += 10) {
    ASSERT(s21_sqrt, sqrt, i);
  }
  for (double i = 0; i < 1; i += 0.001) {
    ASSERT(s21_sqrt, sqrt, i);
  }

  ck_assert_int_eq(isnan(s21_sqrt(-1)), isnan(sqrt(-1)));
}
END_TEST

START_TEST(s21_fabs_f) {
  double args[] = {0, -1, 1};

  ASSERT_ARGS(s21_fabs, fabs);

  ck_assert_int_eq(isinf(s21_fabs(S21_INF)), isinf(fabs(S21_INF)));
}
END_TEST

START_TEST(s21_abs_f) {
  int args[] = {0, -1, 1, INT_MAX, INT_MIN};
  for (int i = 0; i < LEN_ARR(args); i++) {
    ck_assert_int_eq(s21_abs(args[i]), abs(args[i]));
  }
}
END_TEST

Suite *main_suite(void) {
  Suite *s;
  s = suite_create("Func Check");

  TCase *tc_ceil;
  TCase *tc_floor;
  TCase *tc_tan;
  TCase *tc_cos;
  TCase *tc_sin;
  TCase *tc_abs;
  TCase *tc_atan;
  TCase *tc_acos;
  TCase *tc_asin;
  TCase *tc_fmod;
  TCase *tc_exp;
  TCase *tc_log;
  TCase *tc_sqrt;
  TCase *tc_fabs;

  tc_fabs = tcase_create("Fabs");
  suite_add_tcase(s, tc_fabs);
  tcase_add_test(tc_fabs, s21_fabs_f);

  tc_sqrt = tcase_create("Sqrt");
  suite_add_tcase(s, tc_sqrt);
  tcase_add_test(tc_sqrt, s21_sqrt_f);

  tc_log = tcase_create("Log");
  suite_add_tcase(s, tc_log);
  tcase_add_test(tc_log, s21_log_f);

  tc_exp = tcase_create("Exp");
  suite_add_tcase(s, tc_exp);
  tcase_add_test(tc_exp, s21_exp_f);

  tc_fmod = tcase_create("Fmod");
  suite_add_tcase(s, tc_fmod);
  tcase_add_test(tc_fmod, s21_fmod_f);

  tc_asin = tcase_create("Asin");
  suite_add_tcase(s, tc_asin);
  tcase_add_test(tc_asin, s21_asin_f);

  tc_acos = tcase_create("Acos");
  suite_add_tcase(s, tc_acos);
  tcase_add_test(tc_acos, s21_acos_f);

  tc_atan = tcase_create("Atan");
  suite_add_tcase(s, tc_atan);
  tcase_add_test(tc_atan, s21_atan_f);

  tc_abs = tcase_create("Abs");
  suite_add_tcase(s, tc_abs);
  tcase_add_test(tc_abs, s21_abs_f);

  tc_sin = tcase_create("Sin");
  suite_add_tcase(s, tc_sin);
  tcase_add_test(tc_sin, s21_sin_f);

  tc_cos = tcase_create("Cos");
  suite_add_tcase(s, tc_cos);
  tcase_add_test(tc_cos, s21_cos_f);

  tc_tan = tcase_create("Tan");
  suite_add_tcase(s, tc_tan);
  tcase_add_test(tc_tan, s21_tan_f);

  tc_floor = tcase_create("Floor");
  suite_add_tcase(s, tc_floor);
  tcase_add_test(tc_floor, s21_floor_f);

  tc_ceil = tcase_create("Ceil");
  suite_add_tcase(s, tc_ceil);
  tcase_add_test(tc_ceil, s21_ceil_f);

  return s;
}

int main(void) {
  int no_failed = 0;
  SRunner *runner;

  runner = srunner_create(main_suite());
  srunner_add_suite(runner, pow_suite());
  srunner_add_suite(runner, ceil_suite());
  srunner_add_suite(runner, floor_suite());

  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}