#include "s21_tests.h"

START_TEST(test_s21_sum_matrix_1) {
  matrix_t A, B, C;
  int code = 0;
  code += s21_create_matrix(12, 7, &A);
  code += s21_create_matrix(12, 7, &B);
  if (!code) {
    s21_fill_matrix_random(&A, 0);
    s21_fill_matrix_random(&B, 0);
    code = s21_sum_matrix(&A, &B, &C);
    ck_assert_int_eq(0, code);
    printf("\n");
    s21_print_matrix(A, 0);
    printf("\n\n");
    s21_print_matrix(B, 0);
    printf("\n\n");
    s21_print_matrix(C, 0);
    printf("\n");
    for (int i = 0; i < A.rows; i++) {
      for (int j = 0; j < A.columns; j++) {
        ck_assert_double_eq_tol(B.matrix[i][j] + A.matrix[i][j], C.matrix[i][j],
                                1e-7);
      }
    }
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_s21_sum_matrix_2) {
  matrix_t A, B, C;
  int code = 0;
  code += s21_create_matrix(179, 7, &A);
  code += s21_create_matrix(179, 7, &B);
  if (!code) {
    s21_fill_matrix_random(&A, 1);
    s21_fill_matrix_random(&B, 1);
    s21_sum_matrix(&A, &B, &C);
    for (int i = 0; i < A.rows; i++) {
      for (int j = 0; j < A.columns; j++) {
        ck_assert_double_eq_tol(B.matrix[i][j] + A.matrix[i][j], C.matrix[i][j],
                                1e-7);
      }
    }
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_s21_sum_matrix_3) {
  matrix_t A, B, C;
  int code = 0;
  code += s21_create_matrix(179, 179, &A);
  code += s21_create_matrix(179, 179, &B);
  if (!code) {
    s21_fill_matrix_random(&A, 2);
    s21_fill_matrix_random(&B, 2);
    s21_sum_matrix(&A, &B, &C);
    for (int i = 0; i < A.rows; i++) {
      for (int j = 0; j < A.columns; j++) {
        ck_assert_double_eq_tol(B.matrix[i][j] + A.matrix[i][j], C.matrix[i][j],
                                1e-7);
      }
    }
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_s21_sum_matrix_4) {
  matrix_t A, B, C;
  int code = 0, errors = 0;
  code += s21_create_matrix(58, 58, &A);
  code += s21_create_matrix(58, 1, &B);
  if (!code) {
    s21_fill_matrix_random(&A, 0);
    s21_fill_matrix_random(&B, 0);
    errors = s21_sum_matrix(&A, &B, &C);
    ck_assert_int_ne(0, errors);
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sum_matrix_5) {
  matrix_t A, B;
  int code = 0;
  code = s21_sum_matrix(&A, &B, NULL);
  ck_assert_int_ne(0, code);
}
END_TEST

START_TEST(test_s21_sum_matrix_6) {
  matrix_t A, B, C;
  int code = 0;
  code += s21_create_matrix(120, 77, &A);
  code += s21_create_matrix(120, 77, &B);
  code += s21_create_matrix(120, 77, &C);
  if (!code) {
    s21_fill_matrix_random(&A, 0);
    s21_fill_matrix_random(&B, 0);
    code = s21_sum_matrix(&A, &B, &C);
    ck_assert_int_eq(0, code);
    for (int i = 0; i < A.rows; i++) {
      for (int j = 0; j < A.columns; j++) {
        ck_assert_double_eq_tol(B.matrix[i][j] + A.matrix[i][j], C.matrix[i][j],
                                1e-7);
      }
    }
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_s21_sum_matrix_7) {
  matrix_t A, B, C;
  int code = 0;
  code += s21_create_matrix(120, 77, &A);
  code += s21_create_matrix(120, 77, &B);
  if (!code) {
    s21_fill_matrix_random(&A, 0);
    s21_fill_matrix_random(&B, 0);
    int acol = A.columns;
    A.columns = INT_MAX;
    int arow = A.rows;
    A.rows = INT_MAX;
    int bcol = B.columns;
    B.columns = INT_MAX;
    int brow = B.rows;
    B.rows = INT_MAX;
    code = s21_sum_matrix(&A, &B, &C);
    ck_assert_int_ne(0, code);
    A.columns = acol;
    A.rows = arow;
    B.columns = bcol;
    B.rows = brow;
  }
  ck_assert_int_ne(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *s21_sum_matrix_suite(void) {
  Suite *sum_matrix = suite_create("s21_sum_matrix");
  TCase *tc_s21_sum_matrix = tcase_create("test_sum_matrix");
  tcase_add_test(tc_s21_sum_matrix, test_s21_sum_matrix_1);
  tcase_add_test(tc_s21_sum_matrix, test_s21_sum_matrix_2);
  tcase_add_test(tc_s21_sum_matrix, test_s21_sum_matrix_3);
  tcase_add_test(tc_s21_sum_matrix, test_s21_sum_matrix_4);
  tcase_add_test(tc_s21_sum_matrix, test_s21_sum_matrix_5);
  tcase_add_test(tc_s21_sum_matrix, test_s21_sum_matrix_6);
  tcase_add_test(tc_s21_sum_matrix, test_s21_sum_matrix_7);
  suite_add_tcase(sum_matrix, tc_s21_sum_matrix);
  return sum_matrix;
}
