#include "s21_matrix.h"

int main() {
  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  s21_remove_matrix(&A);
  return 0;
}