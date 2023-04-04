#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!(s21_is_ok(A) && s21_is_ok(B) && result)) {
    return WRONG_MATRIX;
  }
  if (A->columns != B->columns || A->rows != B->rows) {
    return CALC_ERROR;
  }
  if (s21_create_matrix(A->rows, A->columns, result)) {
    return WRONG_MATRIX;
  }
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (result->matrix[i] + j) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
  return OK;
}
