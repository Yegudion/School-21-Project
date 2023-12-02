#include "s21_matrix.h"

#include <math.h>

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = ALLOC_FAIL;
  if (rows > 0 && columns > 0) {
    result->columns = columns;
    result->rows = rows;

    result->matrix = (double **)calloc((size_t)rows, sizeof(double *));
    if (result->matrix) {
      for (int i = 0; i < rows; ++i) {
        if (!(result->matrix[i] =
                  (double *)calloc((size_t)columns, sizeof(double)))) {
          error = ALLOC_FAIL;
          break;
        }
      }
      error = OK;
    }
  } else {
    error = INCORRECT_MATRIX;
  }
  return error;
}

void s21_remove_matrix(matrix_t *A) {
  if (A) {
    for (int x = 0; x < A->rows; x++) {
      free(A->matrix[x]);
    }
    free(A->matrix);
    A->matrix = NULL;
    A->columns = 0;
    A->rows = 0;
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = SUCCESS;

  if (!(A->rows == B->rows && A->columns == B->columns)) {
    result = 0;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (!(A->matrix[i][j] == B->matrix[i][j])) result = FAILURE;
      }

      if (result == FAILURE) break;
    }
  }
  return result;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;

  if (!(A->rows == B->rows && A->columns == B->columns)) {
    error = 2;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        // printf("\ncheck i: %d  j: %d \n", i, j);
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        // printf("\ncheck2 i: %d  j: %d \n", i, j);
      }
    }
  }
  return error;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;

  if (!(A->rows == B->rows && A->columns == B->columns)) {
    error = 2;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
  return error;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = 0;

  if (!(A->rows && A->columns)) {
    error=1;
  }
    else{
          s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
    }

  return error;
}

double mult_element(matrix_t *a, matrix_t *b, int i, int j) {
  double result = 0;
  for (int k = 0; k < a->columns; k++) {
    result += a->matrix[i][k] * b->matrix[k][j];
  }

  return 0;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;

  if (!(A->columns == B->rows)) {
    error = 2;
  } else {
    result->rows = A->rows;
    result->columns = B->columns;

    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; result->columns; j++) {
        result->matrix[i][j] = mult_element(A, B, i, j);
      }
    }
  }

  return error;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error = 0;

  result->columns = A->rows;
  result->rows = A->columns;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }

  return error;
}

void fill_lower_matrix(
    matrix_t *A, matrix_t *A_low, int k,
    int g) {  // k и g это строка и столбец которые вычеркиваются
  int i_low = 0, j_low = 0;

  for (int i = 0; i < A->rows; i++) {
    if (i == g) continue;
    for (int j = 0; j < A->columns; j++) {
      if (j == k) continue;
      A_low->matrix[++i_low][++j_low] = A->matrix[i][j];
    }
  }
}

int s21_determinant(matrix_t *A, double *result) {
  int error = 0;
  *result = 0;
  if (A->rows != A->columns) {
    error = 2;
  } else {
    int N = A->rows;  //размерность матрицы
    for (int k = 0; k < N; k++) {
      if (N > 2) {
        matrix_t A_low;
        double result_low = 0;
        s21_create_matrix(N - 1, N - 1, &A_low);
        fill_lower_matrix(A, &A_low, k, 0);
        s21_determinant(&A_low, &result_low);
        *result += (pow(-1, k + 2) * result_low * A->matrix[0][k]);
        s21_remove_matrix(&A_low);
      } else if (N == 2) {
        *result = A->matrix[0][0] * A->matrix[1][1] -
                  A->matrix[0][1] * A->matrix[1][0];
      } else if (N == 1) {
        *result = A->matrix[0][0];
      } else if (N == 0) {
        error = 1;
      }
    }
  }
  return error;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = 0;
  if (A->rows != A->columns) {
    error = 2;
  } else {
    int N = A->rows;

    for (int i; i < N; i++) {
      for (int j; j < N; j++) {
        matrix_t det_low;
        double det_result;
        s21_create_matrix(N - 1, N - 1, &det_low);
        fill_lower_matrix(A, &det_low, i, j);
        s21_determinant(&det_low, &det_result);
        result->matrix[i][j] = pow(-1, i + j) * det_result;
        s21_remove_matrix(&det_low);
      }
    }
  }

  return error;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  double det;
  int error = s21_determinant(A, &det);
  if (!(error == 0 && det != 0)) {
    error = 1;
  } else {
    int N = A->rows;
    s21_calc_complements(A, result);
    s21_transpose(A, result);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        result->matrix[i][j] = (1 / det) * result->matrix[i][j];
      }
    }
  }

  return error;
}
