#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!(s21_is_ok(A) && s21_is_ok(B) && result)) {
    return WRONG_MATRIX;
  }
  if (A->columns != B->rows) {
    return CALC_ERROR;
  }

  if (s21_create_matrix(A->rows, B->columns, result)) {
    return WRONG_MATRIX;
  }
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      if (result->matrix[i] + j) {
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
  return OK;
}
