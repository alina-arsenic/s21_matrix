#include "s21_matrix.h"

// подсчет по определению детерминанта, сложность O(n!)
double recursive_det(matrix_t A) {
    double result = 0;
    if (A.rows == 1) {
        result = A.matrix[0][0];
    } else if (A.rows == 2) {
        result = A.matrix[0][0] * A.matrix[1][1] - A.matrix[0][1] * A.matrix[1][0];
    } else {
        matrix_t minor;
        int sign = 1;
        for (int j = 0; j < A.rows; j++) {
            s21_get_minor(&A, 0, j, &minor);
            result += sign * A.matrix[0][j] * recursive_det(minor);
            sign *= -1;
            s21_remove_matrix(&minor);
        }
    }
    return result;
}

int gauss_elimination(matrix_t A){
    int n = A.columns;
    int swap_count = 0;
    for (int i = 0; i < n-1; i++) {
        for (int k = i+1; k < n; k++) {
            if (fabs(A.matrix[i][i]) < fabs(A.matrix[k][i])) {
                swap_count += 1;
                for (int j=0; j < n; j++) {                
                    double temp;
                    temp = A.matrix[i][j];
                    A.matrix[i][j] = A.matrix[k][j];
                    A.matrix[k][j] = temp;
                }
            }
        }
        for (int k = i+1; k < n; k++) {
            if (A.matrix[i][i] == 0) {
                // ЭТО + ПЕРЕПОЛНЕНИЕ
            }
            double term = A.matrix[k][i] / A.matrix[i][i];
            for (int j = 0; j < n; j++) {
                A.matrix[k][j] -= term * A.matrix[i][j];
            }
        }
    }
    return swap_count;       
}

// подсчтет методом Гаусса, сложность O(n^3)
double gauss_det(matrix_t A) {
    int n = A.columns;
    double det = 1;
    matrix_t triangle;
    if (!s21_create_matrix(n, n, &triangle)) {
        s21_copy_matrix(&A, &triangle);
        int swap_count = gauss_elimination(triangle);
        for(int i = 0; i < n; i++){
            det *= triangle.matrix[i][i];
        }
        det *= pow(-1,swap_count);
        s21_remove_matrix(&triangle);
    }
    return det;
}

int s21_determinant(matrix_t *A, double *result) {
    if (!((s21_is_ok(A) && result))) {
        return WRONG_MATRIX;
    }
    if (A->columns != A->rows) {
        return CALC_ERROR;
    }
    if (A->columns < 6) {
        *result = recursive_det(*A);
    } else {
        *result = gauss_det(*A);
    }
    return OK;
}
