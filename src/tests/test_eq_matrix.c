#include "s21_tests.h"

START_TEST(test_s21_eq_matrix_1) {
    matrix_t A, B;
    int code = 0;
    code += s21_create_matrix(12, 7, &A);
    code += s21_create_matrix(12, 7, &B);
    if (!code) {
        s21_fill_matrix_random(&A, 0);
        for (int i = 0; i < A.rows; i++) {
            for (int j = 0; j < A.columns; j++) {
                B.matrix[i][j] = A.matrix[i][j];
            }
        }
        printf("\n");
        s21_print_matrix(A, 0);
        printf("\n\n");
        s21_print_matrix(B, 0);
        printf("\n");
        int is_eq = s21_eq_matrix(&A, &B);
        ck_assert_int_eq(1, is_eq);
    }
    ck_assert_int_eq(0, code);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_2) {
    matrix_t A, B;
    int code = 0;
    code += s21_create_matrix(32, 45, &A);
    code += s21_create_matrix(32, 45, &B);
    if (!code) {
        s21_fill_matrix_random(&A, 1);
        for (int i = 0; i < A.rows; i++) {
            for (int j = 0; j < A.columns; j++) {
                B.matrix[i][j] = A.matrix[i][j];
            }
        }
        int is_eq = s21_eq_matrix(&A, &B);
        ck_assert_int_eq(1, is_eq);
    }
    ck_assert_int_eq(0, code);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_3) {
    matrix_t A, B;
    int code = 0;
    code += s21_create_matrix(100, 67, &A);
    code += s21_create_matrix(100, 67, &B);
    if (!code) {
        s21_fill_matrix_random(&A, 2);
        for (int i = 0; i < A.rows; i++) {
            for (int j = 0; j < A.columns; j++) {
                B.matrix[i][j] = A.matrix[i][j];
            }
        }
        int is_eq = s21_eq_matrix(&A, &B);
        ck_assert_int_eq(1, is_eq);
    }
    ck_assert_int_eq(0, code);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_4) {
    matrix_t A, B;
    int code = 0;
    code += s21_create_matrix(12, 7, &A);
    code += s21_create_matrix(12, 7, &B);
    if (!code) {
        s21_fill_matrix_random(&A, 0);
        for (int i = 0; i < A.rows; i++) {
            for (int j = 0; j < A.columns; j++) {
                B.matrix[i][j] = A.matrix[i][j] + 1;
            }
        }
        int is_eq = s21_eq_matrix(&A, &B);
        ck_assert_int_eq(0, is_eq);
    }
    ck_assert_int_eq(0, code);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_5) {
    matrix_t A, B;
    int code = 0;
    code += s21_create_matrix(32, 45, &A);
    code += s21_create_matrix(32, 45, &B);
    if (!code) {
        s21_fill_matrix_random(&A, 1);
        for (int i = 0; i < A.rows; i++) {
            for (int j = 0; j < A.columns; j++) {
                B.matrix[i][j] = A.matrix[i][j] + 1;
            }
        }
        int is_eq = s21_eq_matrix(&A, &B);
        ck_assert_int_eq(0, is_eq);
    }
    ck_assert_int_eq(0, code);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_6) {
    matrix_t A, B;
    int code = 0;
    code += s21_create_matrix(100, 67, &A);
    code += s21_create_matrix(100, 67, &B);
    if (!code) {
        s21_fill_matrix_random(&A, 2);
        for (int i = 0; i < A.rows; i++) {
            for (int j = 0; j < A.columns; j++) {
                B.matrix[i][j] = A.matrix[i][j] + 1;
            }
        }
        int is_eq = s21_eq_matrix(&A, &B);
        ck_assert_int_eq(0, is_eq);
    }
    ck_assert_int_eq(0, code);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_7) {
    matrix_t A, B;
    int code = 0;
    code += s21_create_matrix(1, 7, &A);
    code += s21_create_matrix(12, 7, &B);
    if (!code) {
        int is_eq = s21_eq_matrix(&A, &B);
        ck_assert_int_eq(0, is_eq);
    }
    ck_assert_int_eq(0, code);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_8) {
    matrix_t A, B;
    int code1, code2;
    code1 = s21_create_matrix(0, 7, &A);
    code2 = s21_create_matrix(12, 7, &B);
    ck_assert_int_eq(1, code1);
    ck_assert_int_eq(0, code2);
    s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_9) {
    matrix_t A, B;
    int code1, code2;
    code1 = s21_create_matrix(0, 7, &A);
    code2 = s21_create_matrix(0, 0, &B);
    ck_assert_int_eq(1, code1);
    ck_assert_int_eq(1, code2);
}
END_TEST

START_TEST(test_s21_eq_matrix_10) {
    matrix_t A, B;
    A.rows = 0;
    int is_eq = s21_eq_matrix(&A, &B);
    ck_assert_int_eq(0, is_eq);
}
END_TEST

START_TEST(test_s21_eq_matrix_11) {
    matrix_t A, B;
    int is_eq = s21_eq_matrix(&A, &B);
    ck_assert_int_eq(0, is_eq);
}
END_TEST

START_TEST(test_s21_eq_matrix_12) {
    matrix_t A;
    int code = s21_create_matrix(INT_MAX, INT_MAX, &A);
    ck_assert_int_eq(1, code);
}
END_TEST

Suite *s21_eq_matrix_suite(void) {
    Suite *eq_matrix = suite_create("s21_eq_matrix");
    TCase *tc_s21_eq_matrix = tcase_create("test_eq_matrix");
    tcase_add_test(tc_s21_eq_matrix, test_s21_eq_matrix_1);
    tcase_add_test(tc_s21_eq_matrix, test_s21_eq_matrix_2);
    tcase_add_test(tc_s21_eq_matrix, test_s21_eq_matrix_3);
    tcase_add_test(tc_s21_eq_matrix, test_s21_eq_matrix_4);
    tcase_add_test(tc_s21_eq_matrix, test_s21_eq_matrix_5);
    tcase_add_test(tc_s21_eq_matrix, test_s21_eq_matrix_6);
    tcase_add_test(tc_s21_eq_matrix, test_s21_eq_matrix_7);
    tcase_add_test(tc_s21_eq_matrix, test_s21_eq_matrix_8);
    tcase_add_test(tc_s21_eq_matrix, test_s21_eq_matrix_9);
    tcase_add_test(tc_s21_eq_matrix, test_s21_eq_matrix_10);
    tcase_add_test(tc_s21_eq_matrix, test_s21_eq_matrix_11);
    tcase_add_test(tc_s21_eq_matrix, test_s21_eq_matrix_12);
    suite_add_tcase(eq_matrix, tc_s21_eq_matrix);
    return eq_matrix;
}
