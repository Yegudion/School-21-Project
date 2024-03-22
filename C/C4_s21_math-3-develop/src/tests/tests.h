#pragma once

#define _GNU_SOURCE

#include "check.h"
#include "math.h"
#include "s21_math.h"
#include "stdio.h"
#include "stdlib.h"

#define LEN_ARR(arr) (int)(sizeof(arr) / sizeof(arr[0]))

#define ASSERT_MSG_FMT "%s %.7lf: s21: %.7Lf f: %.7Lf, equal = %d\n"

static inline void PRINT(long double (*f21)(double), double (*f)(double),
                         double value) {
  long double out21 = f21(value);
  long double out = (long double)f(value);
  int equal = EQUAL(out21, out);
  printf(ASSERT_MSG_FMT, "", value, out21, out, equal);
}

#define ASSERT_ARGS(f21, f) assert_args(args, LEN_ARR(args), f21, f)

static inline void ASSERT(long double (*f21)(double), double (*f)(double),
                          double value) {
  long double out21 = f21(value);
  long double out = (long double)f(value);
  int equal = EQUAL(out21, out);
  ck_assert_msg(equal, ASSERT_MSG_FMT, "failed on value", value, out21, out,
                equal);
}

Suite *main_suite(void);
Suite *pow_suite(void);
Suite *ceil_suite(void);
Suite *floor_suite(void);