#include "s21_tests.h"

START_TEST(test_s21_determinant_1) {
  matrix_t A;
  int code = 0;
  code += s21_create_matrix(3, 3, &A);
  if (!code) {
    double det, answer = 0;
    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[0][2] = 3;
    A.matrix[1][0] = 4;
    A.matrix[1][1] = 5;
    A.matrix[1][2] = 6;
    A.matrix[2][0] = 7;
    A.matrix[2][1] = 8;
    A.matrix[2][2] = 9;
    code += s21_determinant(&A, &det);
    printf("\n");
    s21_print_matrix(A, 0);
    printf("\n");
    printf("det = %lf\n\n", det);
    ck_assert_double_eq_tol(det, answer, 1e-7);
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_2) {
  matrix_t A;
  int code = 0;
  code += s21_create_matrix(5, 5, &A);
  if (!code) {
    double det;
    s21_fill_matrix_random(&A, 0);
    A.matrix[1][1] = 0;
    A.matrix[3][3] = 0;
    code += s21_determinant(&A, &det);
    printf("\n");
    s21_print_matrix(A, 0);
    printf("\n");
    printf("det = %lf\n\n", det);
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_3) {
  matrix_t A;
  int code = 0;
  code += s21_create_matrix(11, 11, &A);
  if (!code) {
    double det;
    s21_fill_matrix_random(&A, 2);
    code += s21_determinant(&A, &det);
    printf("\n");
    s21_print_matrix(A, 1);
    printf("\n");
    printf("det = %lf\n\n", det);
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_4) {
  matrix_t A;
  int code = 0;
  code += s21_create_matrix(6, 6, &A);
  if (!code) {
    double det;
    double answer = 1513. * (-10625.362542075346992) *
                    (-9411657554.0933301612) * (-150714.7253847163) *
                    73845025.57847562189 * 9990776021.352732323;
    A.matrix[0][0] = 1513;
    A.matrix[0][1] = 2345;
    A.matrix[0][2] = 2574.425;
    A.matrix[0][3] = 56;
    A.matrix[0][4] = 0.58;
    A.matrix[0][5] = 55654;

    A.matrix[1][0] = 6776;
    A.matrix[1][1] = -123.23432;
    A.matrix[1][2] = -99990999;
    A.matrix[1][3] = 143666;
    A.matrix[1][4] = 99999;
    A.matrix[1][5] = 1.6;

    A.matrix[2][0] = 1;
    A.matrix[2][1] = 999999;
    A.matrix[2][2] = -0.00001;
    A.matrix[2][3] = 12345;
    A.matrix[2][4] = -34564;
    A.matrix[2][5] = 0.7;

    A.matrix[3][0] = 12341436;
    A.matrix[3][1] = -6666.6666;
    A.matrix[3][2] = 123;
    A.matrix[3][3] = 99999;
    A.matrix[3][4] = -1234;
    A.matrix[3][5] = 2.1;

    A.matrix[4][0] = 1991919191;
    A.matrix[4][1] = 5555;
    A.matrix[4][2] = 1345;
    A.matrix[4][3] = 34365;
    A.matrix[4][4] = -756.657;
    A.matrix[4][5] = -2345;

    A.matrix[5][0] = -1919191991;
    A.matrix[5][1] = 99999;
    A.matrix[5][2] = 1345;
    A.matrix[5][3] = 690759;
    A.matrix[5][4] = 543;
    A.matrix[5][5] = 9999999999.999;

    code += s21_determinant(&A, &det);
    ck_assert_double_eq_tol(det, answer, 1e-7);
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_5) {
  matrix_t A;
  int code = 0;
  code += s21_create_matrix(1, 1, &A);
  if (!code) {
    s21_fill_matrix_random(&A, 0);
    double det, answer = A.matrix[0][0];
    code += s21_determinant(&A, &det);
    ck_assert_double_eq_tol(det, answer, 1e-7);
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_6) {
  int code = 0;
  double det;
  code += s21_determinant(NULL, &det);
  ck_assert_int_ne(0, code);
}
END_TEST

START_TEST(test_s21_determinant_7) {
  matrix_t A;
  int code = 0;
  code += s21_create_matrix(8, 1, &A);
  if (!code) {
    double det;
    code += s21_determinant(&A, &det);
  }
  ck_assert_int_ne(0, code);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_8) {
  matrix_t A;
  int code = 0;
  code += s21_create_matrix(8, 8, &A);
  if (!code) {
    double det;
    code += s21_determinant(&A, &det);
    printf("\n");
    s21_print_matrix(A, 0);
    printf("\n");
    printf("det = %lf\n\n", det);
    ck_assert_double_eq_tol(det, 0, 1e-7);
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_9) {
  matrix_t A;
  int code = 0;
  code += s21_create_matrix(7, 7, &A);
  if (!code) {
    s21_fill_matrix_random(&A, 0);
    double det, answer = 0;
    for (int i = 0; i <= 0; i++) {
      for (int j = 0; j < A.columns; j++) {
        A.matrix[i][j] = 0;
      }
    }
    code += s21_determinant(&A, &det);
    printf("\n");
    s21_print_matrix(A, 0);
    printf("\n");
    printf("det = %lf\n\n", det);
    ck_assert_double_eq_tol(det, answer, 1e-7);
  }
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_determinant_suite(void) {
  Suite *determinant = suite_create("s21_determinant");
  TCase *tc_s21_determinant = tcase_create("test_determinant");
  tcase_add_test(tc_s21_determinant, test_s21_determinant_1);
  tcase_add_test(tc_s21_determinant, test_s21_determinant_2);
  tcase_add_test(tc_s21_determinant, test_s21_determinant_3);
  tcase_add_test(tc_s21_determinant, test_s21_determinant_4);
  tcase_add_test(tc_s21_determinant, test_s21_determinant_5);
  tcase_add_test(tc_s21_determinant, test_s21_determinant_6);
  tcase_add_test(tc_s21_determinant, test_s21_determinant_7);
  tcase_add_test(tc_s21_determinant, test_s21_determinant_8);
  tcase_add_test(tc_s21_determinant, test_s21_determinant_9);
  suite_add_tcase(determinant, tc_s21_determinant);
  return determinant;
}
