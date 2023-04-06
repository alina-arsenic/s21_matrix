#include "s21_tests.h"

START_TEST(test_s21_mult_number_1) {
  matrix_t A, C;
  int code = 0, errors = 0;
  code += s21_create_matrix(12, 7, &A);
  if (!code) {
    s21_fill_matrix_random(&A, 0);
    code = s21_mult_number(&A, 2, &C);
    ck_assert_int_eq(0, code);
    for (int i = 0; i < A.rows; i++) {
      for (int j = 0; j < A.columns; j++) {
        errors += !(fabs(A.matrix[i][j] * 2 - C.matrix[i][j]) < 1e-6);
      }
    }
    ck_assert_int_eq(0, errors);
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_s21_mult_number_2) {
  matrix_t A, C;
  double number = 9999;
  int code = 0, errors = 0;
  code += s21_create_matrix(345, 23, &A);
  if (!code) {
    s21_fill_matrix_random(&A, 0);
    code = s21_mult_number(&A, number, &C);
    ck_assert_int_eq(0, code);
    for (int i = 0; i < A.rows; i++) {
      for (int j = 0; j < A.columns; j++) {
        errors += !(fabs(A.matrix[i][j] * number - C.matrix[i][j]) < 1e-6);
      }
    }
    ck_assert_int_eq(0, errors);
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_s21_mult_number_3) {
  matrix_t A;
  double number = 5;
  int code = s21_mult_number(&A, number, NULL);
  ck_assert_int_ne(0, code);
}
END_TEST

START_TEST(test_s21_mult_number_4) {
  matrix_t A, C;
  double number = 5;
  int code = 0;
  code += s21_create_matrix(5, 5, &A);
  if (!code) {
    A.columns = 0;
    A.rows = 0;
    code = s21_mult_number(&A, number, &C);
    ck_assert_int_ne(0, code);
  }
  ck_assert_int_ne(0, code);
  A.columns = 5;
  A.rows = 5;
  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_mult_number_suite(void) {
  Suite *mult_number = suite_create("s21_mult_number");
  TCase *tc_s21_mult_number = tcase_create("test_mult_number");
  tcase_add_test(tc_s21_mult_number, test_s21_mult_number_1);
  tcase_add_test(tc_s21_mult_number, test_s21_mult_number_2);
  tcase_add_test(tc_s21_mult_number, test_s21_mult_number_3);
  tcase_add_test(tc_s21_mult_number, test_s21_mult_number_4);
  suite_add_tcase(mult_number, tc_s21_mult_number);
  return mult_number;
}
