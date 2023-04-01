#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    if (!(s21_is_ok(A) && s21_is_ok(B) && result)) {
        return WRONG_MATRIX;
    }
    if (A->columns != B->columns || A->rows != B->rows) {
        return CALC_ERROR;
    }
    if (s21_create_matrix(A->rows, A->columns, result)) {
        return WRONG_MATRIX;
    }
    double a, b;
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            if (result->matrix[i] + j) {
                a = A->matrix[i][j];
                b = B->matrix[i][j];
                if (((a > 0) == (b > 0)) && (fabs(a) > DBL_MAX - fabs(b))) {
                    return CALC_ERROR;  // переполнение
                }
                result->matrix[i][j] = a + b;
            }
        }
    }
    return OK;
}
