#ifndef SRC_S21_UTILS_
#define SRC_S21_UTILS_

#define S21_INF 1.0 / 0.0

#include "s21_matrix.h"

// void s21_print_matrix(matrix_t *source, int big);
int s21_fill_matrix_random(matrix_t *A, int big);
int s21_get_minor(matrix_t *A, int row, int col, matrix_t *result);
int s21_copy_matrix(matrix_t *src, matrix_t *dst);

#endif  //  SRC_S21_UTILS_
