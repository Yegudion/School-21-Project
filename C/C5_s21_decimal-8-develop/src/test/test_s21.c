#include "s21_test.h"

int main() {
  Suite *s = suite_create("Decimal tests");
  SRunner *sr = srunner_create(s);
  int err;

  srunner_add_math_tests(sr);
  srunner_add_others_tests(sr);
  srunner_add_compare_tests(sr);
  srunner_add_convert_tests(sr);

  s21_create_test(sr);
  s21_sign_test(sr);
  s21_scale_factor_test(sr);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);  // CK_ENV?
  err = srunner_ntests_failed(sr);
  srunner_free(sr);

  return err == 0 ? 0 : 1;
}
