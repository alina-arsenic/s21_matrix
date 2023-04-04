#include "s21_tests.h"

START_TEST(test_s21_transpose_1) {
  matrix_t A, B;
  int code = 0;
  code += s21_create_matrix(3, 2, &A);
  if (!code) {
    A.matrix[0][0] = 1;
    A.matrix[1][0] = 2;
    A.matrix[2][0] = 3;
    A.matrix[0][1] = 4;
    A.matrix[1][1] = 5;
    A.matrix[2][1] = 6;
    code += s21_transpose(&A, &B);
    printf("\n");
    s21_print_matrix(A, 0);
    printf("\n\n");
    s21_print_matrix(B, 0);
    printf("\n");
    for (int i = 0; i < A.columns; i++) {
      for (int j = 0; j < A.rows; j++) {
        ck_assert_double_eq(B.matrix[i][j], A.matrix[j][i]);
      }
    }
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_transpose_2) {
  matrix_t A, B;
  int code = 0;
  code += s21_create_matrix(3, 2, &A);
  if (!code) {
    s21_fill_matrix_random(&A, 0);
    code += s21_transpose(&A, &B);
    for (int i = 0; i < A.columns; i++) {
      for (int j = 0; j < A.rows; j++) {
        ck_assert_double_eq(B.matrix[i][j], A.matrix[j][i]);
      }
    }
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_transpose_3) {
  matrix_t A, B;
  int code = 0;
  code += s21_create_matrix(23, 12, &A);
  if (!code) {
    s21_fill_matrix_random(&A, 4);
    code += s21_transpose(&A, &B);
    for (int i = 0; i < A.columns; i++) {
      for (int j = 0; j < A.rows; j++) {
        ck_assert_double_eq(B.matrix[i][j], A.matrix[j][i]);
      }
    }
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_transpose_4) {
  int code = s21_transpose(NULL, NULL);
  ck_assert_int_ne(0, code);
}
END_TEST

START_TEST(test_s21_transpose_5) {
  matrix_t A, B;
  int code = 0;
  code += s21_create_matrix(3, 2, &A);
  if (!code) {
    A.columns = INT_MAX;
    A.rows = INT_MAX;
    code += s21_transpose(&A, &B);
  }
  ck_assert_int_ne(0, code);
  A.columns = 2;
  A.rows = 3;
  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_transpose_suite(void) {
  Suite *transpose = suite_create("s21_transpose");
  TCase *tc_s21_transpose = tcase_create("test_transpose");
  tcase_add_test(tc_s21_transpose, test_s21_transpose_1);
  tcase_add_test(tc_s21_transpose, test_s21_transpose_2);
  tcase_add_test(tc_s21_transpose, test_s21_transpose_3);
  tcase_add_test(tc_s21_transpose, test_s21_transpose_4);
  tcase_add_test(tc_s21_transpose, test_s21_transpose_5);
  suite_add_tcase(transpose, tc_s21_transpose);
  return transpose;
}
