#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!((s21_is_ok(A) && result))) {
    return WRONG_MATRIX;
  }
  if (A->columns != A->rows) {
    return CALC_ERROR;
  }
  if (s21_create_matrix(A->rows, A->columns, result)) {
    return WRONG_MATRIX;
  }

  double det = 0;
  s21_determinant(A, &det);
  if (det == 0) {
    return CALC_ERROR;
  }

  matrix_t complements, transposed;
  s21_calc_complements(A, &complements);
  s21_transpose(&complements, &transposed);
  double coef = 1;
  coef /= det;
  s21_mult_number(&transposed, coef, result);
  s21_remove_matrix(&complements);
  s21_remove_matrix(&transposed);
  return OK;
}
