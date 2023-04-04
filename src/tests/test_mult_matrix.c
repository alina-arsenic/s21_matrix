#include "s21_tests.h"

START_TEST(test_s21_mult_matrix_1) {
  matrix_t A, B, C;
  int code = 0;
  code += s21_create_matrix(3, 2, &A);
  code += s21_create_matrix(2, 3, &B);
  if (!code) {
    A.matrix[0][0] = 1;
    A.matrix[0][1] = 4;

    A.matrix[1][0] = 2;
    A.matrix[1][1] = 5;

    A.matrix[2][0] = 3;
    A.matrix[2][1] = 6;

    B.matrix[0][0] = 1;
    B.matrix[0][1] = -1;
    B.matrix[0][2] = 1;

    B.matrix[1][0] = 2;
    B.matrix[1][1] = 3;
    B.matrix[1][2] = 4;

    code = s21_mult_matrix(&A, &B, &C);
    ck_assert_int_eq(0, code);

    printf("\n");
    s21_print_matrix(A, 0);
    printf("\n\n");
    s21_print_matrix(B, 0);
    printf("\n\n");
    s21_print_matrix(C, 0);
    printf("\n");

    ck_assert_double_eq_tol(C.matrix[0][0], 9, 1e-7);
    ck_assert_double_eq_tol(C.matrix[0][1], 11, 1e-7);
    ck_assert_double_eq_tol(C.matrix[0][2], 17, 1e-7);
    ck_assert_double_eq_tol(C.matrix[1][0], 12, 1e-7);
    ck_assert_double_eq_tol(C.matrix[1][1], 13, 1e-7);
    ck_assert_double_eq_tol(C.matrix[1][2], 22, 1e-7);
    ck_assert_double_eq_tol(C.matrix[2][0], 15, 1e-7);
    ck_assert_double_eq_tol(C.matrix[2][1], 15, 1e-7);
    ck_assert_double_eq_tol(C.matrix[2][2], 27, 1e-7);
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_s21_mult_matrix_2) {
  matrix_t A, B, C;
  int code = 0;
  code += s21_create_matrix(5, 3, &A);
  code += s21_create_matrix(3, 4, &B);
  if (!code) {
    A.matrix[0][0] = 1.123;
    A.matrix[0][1] = 546.999999;
    A.matrix[0][2] = 9;

    A.matrix[1][0] = 1.123456;
    A.matrix[1][1] = 5;
    A.matrix[1][2] = -666;

    A.matrix[2][0] = 9;
    A.matrix[2][1] = -123.456789;
    A.matrix[2][2] = -78.78;

    A.matrix[3][0] = 0;
    A.matrix[3][1] = 1234324;
    A.matrix[3][2] = -34;

    A.matrix[4][0] = 33;
    A.matrix[4][1] = 344.1;
    A.matrix[4][2] = 26;

    B.matrix[0][0] = 1;
    B.matrix[0][1] = -56.666666;
    B.matrix[0][2] = 0.00001;
    B.matrix[0][3] = 888888888;

    B.matrix[1][0] = 1.123123;
    B.matrix[1][1] = -1.123456;
    B.matrix[1][2] = 0;
    B.matrix[1][3] = 3;

    B.matrix[2][0] = -999999.999999;
    B.matrix[2][1] = -0.0000002;
    B.matrix[2][2] = 34;
    B.matrix[2][3] = -5;

    code = s21_mult_matrix(&A, &B, &C);
    ck_assert_int_eq(0, code);

    ck_assert_double_eq_tol(C.matrix[0][0], -8999384.528711123123, 1e-7);
    ck_assert_double_eq_tol(C.matrix[0][1], -678.167098594544, 1e-7);
    ck_assert_double_eq_tol(C.matrix[0][2], 306.00001123, 1e-7);
    ck_assert_double_eq_tol(C.matrix[0][3], 998223817.223997, 1e-7);

    ck_assert_double_eq_tol(C.matrix[1][0], 666000006.738405, 1e-7);
    ck_assert_double_eq_tol(C.matrix[1][1], -69.279652717696, 1e-7);
    ck_assert_double_eq_tol(C.matrix[1][2], -22643.99998876544, 1e-7);
    ck_assert_double_eq_tol(C.matrix[1][3], 998630899.556928, 1e-7);

    ck_assert_double_eq_tol(C.matrix[2][0], 78779870.342761987953, 1e-7);
    ck_assert_double_eq_tol(C.matrix[2][1], -371.301707901216, 1e-7);
    ck_assert_double_eq_tol(C.matrix[2][2], -2678.51991, 1e-7);
    ck_assert_double_eq_tol(C.matrix[2][3], 8000000015.529633, 1e-7);

    ck_assert_double_eq_tol(C.matrix[3][0], 35386297.673818, 1e-7);
    ck_assert_double_eq_tol(C.matrix[3][1], -1386708.7037372, 1e-7);
    ck_assert_double_eq_tol(C.matrix[3][2], -1156, 1e-7);
    ck_assert_double_eq_tol(C.matrix[3][3], 3703142, 1e-7);

    ck_assert_double_eq_tol(C.matrix[4][0], -25999580.5333497, 1e-7);
    ck_assert_double_eq_tol(C.matrix[4][1], -2256.5811928, 1e-7);
    ck_assert_double_eq_tol(C.matrix[4][2], 884.00033, 1e-7);
    ck_assert_double_eq_tol(C.matrix[4][3], 29333334206.3, 1e-7);
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_s21_mult_matrix_3) {
  matrix_t A, B;
  int code = 0;
  code = s21_mult_matrix(&A, &B, NULL);
  ck_assert_int_ne(0, code);
}
END_TEST

START_TEST(test_s21_mult_matrix_4) {
  matrix_t A, B, C;
  int code = 0;
  code += s21_create_matrix(5, 12, &A);
  code += s21_create_matrix(67, 4, &B);
  code += s21_mult_matrix(&A, &B, &C);
  ck_assert_int_ne(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_mult_matrix_5) {
  matrix_t A, B, C;
  int code = 0;
  code += s21_create_matrix(66666666, 1, &A);
  code += s21_create_matrix(1, INT_MAX, &B);
  code += s21_mult_matrix(&A, &B, &C);
  ck_assert_int_ne(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *s21_mult_matrix_suite(void) {
  Suite *mult_matrix = suite_create("s21_mult_matrix");
  TCase *tc_s21_mult_matrix = tcase_create("test_mult_matrix");
  tcase_add_test(tc_s21_mult_matrix, test_s21_mult_matrix_1);
  tcase_add_test(tc_s21_mult_matrix, test_s21_mult_matrix_2);
  tcase_add_test(tc_s21_mult_matrix, test_s21_mult_matrix_3);
  tcase_add_test(tc_s21_mult_matrix, test_s21_mult_matrix_4);
  tcase_add_test(tc_s21_mult_matrix, test_s21_mult_matrix_5);
  suite_add_tcase(mult_matrix, tc_s21_mult_matrix);
  return mult_matrix;
}
