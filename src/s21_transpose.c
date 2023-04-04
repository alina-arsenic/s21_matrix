#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (!(s21_is_ok(A) && result)) {
    return WRONG_MATRIX;
  }
  if (s21_create_matrix(A->columns, A->rows, result)) {
    return WRONG_MATRIX;
  }
  for (int i = 0; i < A->columns; i++) {
    for (int j = 0; j < A->rows; j++) {
      result->matrix[i][j] = A->matrix[j][i];
    }
  }
  return OK;
}
