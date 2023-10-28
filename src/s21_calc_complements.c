#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (!A || !result) {
    return WRONG_MATRIX;
  }
  if (A->columns != A->rows) {
    return CALC_ERROR;
  }
  if (s21_create_matrix(A->rows, A->columns, result)) {
    return WRONG_MATRIX;
  }
  matrix_t minor;
  double minor_det;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      s21_get_minor(A, i, j, &minor);
      s21_determinant(&minor, &minor_det);
      result->matrix[i][j] = minor_det * pow(-1, i + j);
      s21_remove_matrix(&minor);
    }
  }
  return OK;
}
