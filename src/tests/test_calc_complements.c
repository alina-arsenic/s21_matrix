#include "s21_tests.h"

START_TEST(test_s21_calc_complements_1) {
  matrix_t A, B;
  int code = 0;
  code += s21_create_matrix(3, 3, &A);
  if (!code) {
    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[0][2] = 3;
    A.matrix[1][0] = 0;
    A.matrix[1][1] = 4;
    A.matrix[1][2] = 2;
    A.matrix[2][0] = 5;
    A.matrix[2][1] = 2;
    A.matrix[2][2] = 1;
    code += s21_calc_complements(&A, &B);
    printf("\n");
    s21_print_matrix(A, 0);
    printf("\n\n");
    s21_print_matrix(B, 0);
    printf("\n");
    ck_assert_double_eq_tol(B.matrix[0][0], 0, 1e-7);
    ck_assert_double_eq_tol(B.matrix[0][1], 10, 1e-7);
    ck_assert_double_eq_tol(B.matrix[0][2], -20, 1e-7);
    ck_assert_double_eq_tol(B.matrix[1][0], 4, 1e-7);
    ck_assert_double_eq_tol(B.matrix[1][1], -14, 1e-7);
    ck_assert_double_eq_tol(B.matrix[1][2], 8, 1e-7);
    ck_assert_double_eq_tol(B.matrix[2][0], -8, 1e-7);
    ck_assert_double_eq_tol(B.matrix[2][1], -2, 1e-7);
    ck_assert_double_eq_tol(B.matrix[2][2], 4, 1e-7);
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_calc_complements_2) {
  matrix_t A, B;
  int code = 0;
  code += s21_create_matrix(3, 3, &A);
  if (!code) {
    A.rows = INT_MAX;
    A.columns = INT_MAX;
    code += s21_calc_complements(&A, &B);
  }
  ck_assert_int_ne(0, code);
  A.rows = 3;
  A.columns = 3;
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_calc_complements_3) {
  int code = 0;
  code += s21_calc_complements(NULL, NULL);
  ck_assert_int_ne(0, code);
}
END_TEST

START_TEST(test_s21_calc_complements_4) {
  matrix_t A, B;
  int code = 0;
  code += s21_create_matrix(5, 3, &A);
  if (!code) {
    code += s21_calc_complements(&A, &B);
  }
  ck_assert_int_ne(0, code);
  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_calc_complements_suite(void) {
  Suite *calc_complements = suite_create("s21_calc_complements");
  TCase *tc_s21_calc_complements = tcase_create("test_calc_complements");
  tcase_add_test(tc_s21_calc_complements, test_s21_calc_complements_1);
  tcase_add_test(tc_s21_calc_complements, test_s21_calc_complements_2);
  tcase_add_test(tc_s21_calc_complements, test_s21_calc_complements_3);
  tcase_add_test(tc_s21_calc_complements, test_s21_calc_complements_4);
  suite_add_tcase(calc_complements, tc_s21_calc_complements);
  return calc_complements;
}
