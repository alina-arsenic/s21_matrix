#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
    if (!(s21_is_ok(A) && result)) {
        return WRONG_MATRIX;
    }
    if (s21_create_matrix(A->rows, A->columns, result)) {
        return WRONG_MATRIX;
    }
    double a;
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            if (result->matrix[i] + j) {
                a = A->matrix[i][j];
                if (number && (fabs(a) > fabs(DBL_MAX / number))) {
                    return CALC_ERROR;  // переполнение
                }
                result->matrix[i][j] = a * number;
            }
        }
    }
    return OK;
}
