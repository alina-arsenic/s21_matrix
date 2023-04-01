#include "s21_utils.h"

int s21_is_ok(matrix_t *A)
{
    if (!A || !(A->matrix) || !(A->columns > 0) || !(A->rows > 0))
    {
        return 0;
    }
    return 1;
}

void s21_print_matrix(matrix_t source, int big)
{
    for (int i = 0; i < source.rows; i++)
    {
        for (int j = 0; j < source.columns; j++)
        {
            if (big)
                printf("%.7lf\n", source.matrix[i][j]);
            else
                printf("%13.7lf", source.matrix[i][j]);
        }
        printf("\n");
    }
}

int s21_fill_matrix_random(matrix_t *A, int big)
{
    if (s21_is_ok(A))
    {
        srand(time(NULL));
        for (int i = 0; i < A->rows; i++)
        {
            for (int j = 0; j < A->columns; j++)
            {
                if (A->matrix[i] + j)
                {
                    A->matrix[i][j] = (double)rand();
                    A->matrix[i][j] /= 10e7;
                    if (rand() % 2)
                        A->matrix[i][j] *= -1;
                    for (int k = 0; k < big; k++)
                        A->matrix[i][j] *= (double)rand();
                }
            }
        }
    }
    return OK;
}

int s21_get_minor(matrix_t *A, int row, int col, matrix_t *result) {
    int code = 0;
    if ((s21_is_ok(A) && result)) {
        if (!s21_create_matrix(A->rows - 1, A->columns - 1, result)) {
            if (row >= 0 && col >= 0 && row < A->rows && col < A->columns) {
                int skip = 0;
                for (int i = 0; i < A->rows - 1; i++) {
                    if (i == row) skip = 1;
                    for (int j = 0; j < col; j++) {
                        result->matrix[i][j] = A->matrix[i + skip][j];
                    }
                    for (int j = col + 1; j < A->columns; j++) {
                        result->matrix[i][j - 1] = A->matrix[i + skip][j];
                    }
                }
            }
        }
    }
    return code;
}

int s21_copy_matrix(matrix_t *src, matrix_t *dst) {
    if (src->columns == dst->rows && src->rows == dst->rows) {
        for (int i = 0; i < src->rows; i++) {
            for (int j = 0; j < src->rows; j++) {
                dst->matrix[i][j] = src->matrix[i][j];
            }
        }
    }
    return 0;
}
