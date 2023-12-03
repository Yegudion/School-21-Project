#include "s21_matrix.h"


int main(){

 double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  s21_determinant(&A, &determ);
  //ck_assert_double_eq(determ, -24105.996724156);
  s21_remove_matrix(&A);

  printf("%lf", determ);

    return 0;
}