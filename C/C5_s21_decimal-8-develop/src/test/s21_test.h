#ifndef S21_DEC_TESTS_H_
#define S21_DEC_TESTS_H_

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_decimal.h"

#define SIGN_MASK 0x80000000
#define S21_TRUE 1
#define S21_FALSE 0
#define S21_DECIMAL_NULL {0};

void srunner_add_math_tests(SRunner *sr);
void srunner_add_others_tests(SRunner *sr);
void srunner_add_compare_tests(SRunner *sr);
void srunner_add_convert_tests(SRunner *sr);

void s21_create_test(SRunner *sr);
void s21_sign_test(SRunner *sr);
void s21_scale_factor_test(SRunner *sr);

#endif