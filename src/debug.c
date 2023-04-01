#include <stdio.h>
#include <stdlib.h>
#include "s21_matrix.h"

int main() {
    matrix_t A, B, C;
    s21_create_matrix(3, 3, &A);
    //s21_fill_matrix_random(&A, 0);
    
    A.matrix[0][0] = 2;
    A.matrix[0][1] = 5;
    A.matrix[0][2] = 7;
    A.matrix[1][0] = 6;
    A.matrix[1][1] = 3;
    A.matrix[1][2] = 4;
    A.matrix[2][0] = 5;
    A.matrix[2][1] = -2;
    A.matrix[2][2] = -3;
    
    //double det;
    //int code = s21_determinant(&A, &det);
    //printf("%d\n", code);

    s21_inverse_matrix(&A, &B);

    printf("\n");
    s21_print_matrix(A, 0);
    printf("\n");
    s21_print_matrix(B, 0);
    printf("\n");
    //s21_print_matrix(C, 0);
    printf("\n");
    //printf("%lf\n", det);
    return 0;
}
