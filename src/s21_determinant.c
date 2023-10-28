#include "s21_matrix.h"

double recursive_det(matrix_t A);
int gauss_elimination(matrix_t A, int *swap_count);
int gauss_det(matrix_t A, double *det);

int s21_determinant(matrix_t *A, double *result) {
  if (!A || !result) {
    return WRONG_MATRIX;
  }
  if (A->columns != A->rows) {
    return CALC_ERROR;
  }
  if (A->columns < 6) {
    *result = recursive_det(*A);
  } else {
    if (gauss_det(*A, result)) {
      *result = 0;
    }
  }
  return OK;
}

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

// последовательное исключение переменных
int gauss_elimination(matrix_t A, int *swap_count) {
  int n = A.columns;
  *swap_count = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int k = i + 1; k < n; k++) {
      if (fabs(A.matrix[i][i]) < fabs(A.matrix[k][i])) {
        *swap_count += 1;
        for (int j = 0; j < n; j++) {
          double temp;
          temp = A.matrix[i][j];
          A.matrix[i][j] = A.matrix[k][j];
          A.matrix[k][j] = temp;
        }
      }
    }
    for (int k = i + 1; k < n; k++) {
      if (A.matrix[i][i] == 0) {
        return 1;
      }
      double term = A.matrix[k][i] / A.matrix[i][i];
      for (int j = 0; j < n; j++) {
        A.matrix[k][j] -= term * A.matrix[i][j];
      }
    }
  }
  return 0;
}

// подсчтет методом Гаусса, сложность O(n^3)
int gauss_det(matrix_t A, double *det) {
  int n = A.columns;
  int swap_count = 0, code = 1;
  *det = 1;
  matrix_t triangle;
  if (!s21_create_matrix(n, n, &triangle)) {
    s21_copy_matrix(&A, &triangle);
    code = gauss_elimination(triangle, &swap_count);
    if (!code) {
      for (int i = 0; i < n; i++) {
        *det *= triangle.matrix[i][i];
      }
      *det *= pow(-1, swap_count);
    }
    s21_remove_matrix(&triangle);
  }
  return code;
}
