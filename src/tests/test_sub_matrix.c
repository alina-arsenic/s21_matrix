#include "s21_tests.h"

START_TEST(test_s21_sub_matrix_1) {
  matrix_t A, B, C;
  int code = 0, errors = 0;
  code += s21_create_matrix(12, 7, &A);
  code += s21_create_matrix(12, 7, &B);
  if (!code) {
    s21_fill_matrix_random(&A, 0);
    s21_fill_matrix_random(&B, 0);
    code = s21_sub_matrix(&A, &B, &C);
    ck_assert_int_eq(0, code);
    for (int i = 0; i < A.rows; i++) {
      for (int j = 0; j < A.columns; j++) {
        errors +=
            !(fabs(A.matrix[i][j] - B.matrix[i][j] - C.matrix[i][j]) < 1e-6);
      }
    }
    ck_assert_int_eq(0, errors);
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_s21_sub_matrix_2) {
  matrix_t A, B, C;
  int code = 0, errors = 0;
  code += s21_create_matrix(179, 7, &A);
  code += s21_create_matrix(179, 7, &B);
  if (!code) {
    s21_fill_matrix_random(&A, 1);
    s21_fill_matrix_random(&B, 1);
    s21_sub_matrix(&A, &B, &C);
    for (int i = 0; i < A.rows; i++) {
      for (int j = 0; j < A.columns; j++) {
        errors +=
            !(fabs(A.matrix[i][j] - B.matrix[i][j] - C.matrix[i][j]) < 1e-6);
      }
    }
    ck_assert_int_eq(0, errors);
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_s21_sub_matrix_3) {
  matrix_t A, B, C;
  int code = 0, errors = 0;
  code += s21_create_matrix(179, 179, &A);
  code += s21_create_matrix(179, 179, &B);
  if (!code) {
    s21_fill_matrix_random(&A, 2);
    s21_fill_matrix_random(&B, 2);
    s21_sub_matrix(&A, &B, &C);
    for (int i = 0; i < A.rows; i++) {
      for (int j = 0; j < A.columns; j++) {
        errors +=
            !(fabs(A.matrix[i][j] - B.matrix[i][j] - C.matrix[i][j]) < 1e-6);
      }
    }
    ck_assert_int_eq(0, errors);
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_s21_sub_matrix_4) {
  matrix_t A, B, C;
  int code = 0, errors = 0;
  code += s21_create_matrix(58, 58, &A);
  code += s21_create_matrix(58, 1, &B);
  if (!code) {
    s21_fill_matrix_random(&A, 0);
    s21_fill_matrix_random(&B, 0);
    errors = s21_sub_matrix(&A, &B, &C);
    ck_assert_int_ne(0, errors);
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sub_matrix_5) {
  matrix_t A, B;
  int code = 0;
  code = s21_sub_matrix(&A, &B, NULL);
  ck_assert_int_ne(0, code);
}
END_TEST

START_TEST(test_s21_sub_matrix_6) {
  matrix_t A, B, C;
  int code = 0, errors = 0;
  code += s21_create_matrix(120, 77, &A);
  code += s21_create_matrix(120, 77, &B);
  code += s21_create_matrix(120, 77, &C);
  if (!code) {
    s21_fill_matrix_random(&A, 0);
    s21_fill_matrix_random(&B, 0);
    code = s21_sub_matrix(&A, &B, &C);
    ck_assert_int_eq(0, code);
    for (int i = 0; i < A.rows; i++) {
      for (int j = 0; j < A.columns; j++) {
        errors +=
            !(fabs(A.matrix[i][j] - B.matrix[i][j] - C.matrix[i][j]) < 1e-6);
      }
    }
    ck_assert_int_eq(0, errors);
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_s21_sub_matrix_7) {
  matrix_t A, B, C;
  int code = 0;
  code += s21_create_matrix(120, 77, &A);
  code += s21_create_matrix(120, 77, &B);
  if (!code) {
    s21_fill_matrix_random(&A, 0);
    s21_fill_matrix_random(&B, 0);
    int acol = A.columns;
    A.columns = 0;
    int arow = A.rows;
    A.rows = 0;
    int bcol = B.columns;
    B.columns = 0;
    int brow = B.rows;
    B.rows = 0;
    code = s21_sub_matrix(&A, &B, &C);
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

Suite *s21_sub_matrix_suite(void) {
  Suite *sub_matrix = suite_create("s21_sub_matrix");
  TCase *tc_s21_sub_matrix = tcase_create("test_sub_matrix");
  tcase_add_test(tc_s21_sub_matrix, test_s21_sub_matrix_1);
  tcase_add_test(tc_s21_sub_matrix, test_s21_sub_matrix_2);
  tcase_add_test(tc_s21_sub_matrix, test_s21_sub_matrix_3);
  tcase_add_test(tc_s21_sub_matrix, test_s21_sub_matrix_4);
  tcase_add_test(tc_s21_sub_matrix, test_s21_sub_matrix_5);
  tcase_add_test(tc_s21_sub_matrix, test_s21_sub_matrix_6);
  tcase_add_test(tc_s21_sub_matrix, test_s21_sub_matrix_7);
  suite_add_tcase(sub_matrix, tc_s21_sub_matrix);
  return sub_matrix;
}
