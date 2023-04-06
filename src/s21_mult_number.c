#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (!A || !result) {
    return WRONG_MATRIX;
  }
  if (s21_create_matrix(A->rows, A->columns, result)) {
    return WRONG_MATRIX;
  }
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (result->matrix[i] + j) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return OK;
}
