#include "s21_tests.h"

START_TEST(test_s21_inverse_matrix_1) {
  matrix_t A, B;
  int code = 0;
  code += s21_create_matrix(3, 3, &A);
  if (!code) {
    A.matrix[0][0] = 2;
    A.matrix[0][1] = 5;
    A.matrix[0][2] = 7;
    A.matrix[1][0] = 6;
    A.matrix[1][1] = 3;
    A.matrix[1][2] = 4;
    A.matrix[2][0] = 5;
    A.matrix[2][1] = -2;
    A.matrix[2][2] = -3;
    code += s21_inverse_matrix(&A, &B);
    printf("\n");
    s21_print_matrix(A, 0);
    printf("\n\n");
    s21_print_matrix(B, 0);
    printf("\n");
    ck_assert_double_eq_tol(B.matrix[0][0], 1, 1e-7);
    ck_assert_double_eq_tol(B.matrix[0][1], -1, 1e-7);
    ck_assert_double_eq_tol(B.matrix[0][2], 1, 1e-7);
    ck_assert_double_eq_tol(B.matrix[1][0], -38, 1e-7);
    ck_assert_double_eq_tol(B.matrix[1][1], 41, 1e-7);
    ck_assert_double_eq_tol(B.matrix[1][2], -34, 1e-7);
    ck_assert_double_eq_tol(B.matrix[2][0], 27, 1e-7);
    ck_assert_double_eq_tol(B.matrix[2][1], -29, 1e-7);
    ck_assert_double_eq_tol(B.matrix[2][2], 24, 1e-7);
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_inverse_matrix_2) {
  matrix_t A, B;
  int code = 0;
  code += s21_create_matrix(3, 3, &A);
  if (!code) {
    A.rows = INT_MAX;
    A.columns = INT_MAX;
    code += s21_inverse_matrix(&A, &B);
  }
  ck_assert_int_ne(0, code);
  A.rows = 3;
  A.columns = 3;
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_3) {
  int code = 0;
  code += s21_inverse_matrix(NULL, NULL);
  ck_assert_int_ne(0, code);
}
END_TEST

START_TEST(test_s21_inverse_matrix_4) {
  matrix_t A, B;
  int code = 0;
  code += s21_create_matrix(5, 3, &A);
  if (!code) {
    code += s21_inverse_matrix(&A, &B);
  }
  ck_assert_int_ne(0, code);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_5) {
  matrix_t A, B;
  int code = 0;
  code += s21_create_matrix(23, 23, &A);
  if (!code) {
    code += s21_inverse_matrix(&A, &B);
  }
  ck_assert_int_ne(0, code);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_6) {
  matrix_t A, B;
  int code = 0;
  code += s21_create_matrix(11, 11, &A);
  if (!code) {
    s21_fill_matrix_random(&A, 0);
    code += s21_inverse_matrix(&A, &B);
    printf("\n");
    s21_print_matrix(A, 0);
    printf("\n\n");
    s21_print_matrix(B, 0);
    printf("\n");
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_inverse_matrix_7) {
  matrix_t A, B;
  int code = 0;
  code += s21_create_matrix(3, 3, &A);
  if (!code) {
    s21_fill_matrix_random(&A, 4);
    code += s21_inverse_matrix(&A, &B);
    printf("\n");
    s21_print_matrix(A, 1);
    printf("\n\n");
    s21_print_matrix(B, 1);
    printf("\n");
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *s21_inverse_matrix_suite(void) {
  Suite *inverse_matrix = suite_create("s21_inverse_matrix");
  TCase *tc_s21_inverse_matrix = tcase_create("test_inverse_matrix");
  tcase_add_test(tc_s21_inverse_matrix, test_s21_inverse_matrix_1);
  tcase_add_test(tc_s21_inverse_matrix, test_s21_inverse_matrix_2);
  tcase_add_test(tc_s21_inverse_matrix, test_s21_inverse_matrix_3);
  tcase_add_test(tc_s21_inverse_matrix, test_s21_inverse_matrix_4);
  tcase_add_test(tc_s21_inverse_matrix, test_s21_inverse_matrix_5);
  tcase_add_test(tc_s21_inverse_matrix, test_s21_inverse_matrix_6);
  tcase_add_test(tc_s21_inverse_matrix, test_s21_inverse_matrix_7);
  suite_add_tcase(inverse_matrix, tc_s21_inverse_matrix);
  return inverse_matrix;
}
