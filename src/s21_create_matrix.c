#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    if (!result || !(rows > 0) || !(columns > 0)) {
        return WRONG_MATRIX;
    }
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double**)calloc(rows, sizeof(double*));
    if (!result->matrix) {
        return WRONG_MATRIX;
    }
    for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double*)calloc(columns, sizeof(double));
        if (!result->matrix[i]) {
            return WRONG_MATRIX;
        }
    }
    return OK;
}
