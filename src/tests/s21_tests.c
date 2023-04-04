#include "s21_tests.h"

int main(void) {
  srand(time(NULL));

  SRunner *sr;

  Suite *eq_matrix = s21_eq_matrix_suite();
  Suite *sum_matrix = s21_sum_matrix_suite();
  Suite *sub_matrix = s21_sub_matrix_suite();
  Suite *mult_number = s21_mult_number_suite();
  Suite *mult_matrix = s21_mult_matrix_suite();
  Suite *transpose = s21_transpose_suite();
  Suite *calc_complements = s21_calc_complements_suite();
  Suite *determinant = s21_determinant_suite();
  Suite *inverse_matrix = s21_inverse_matrix_suite();

  sr = srunner_create(eq_matrix);
  srunner_add_suite(sr, sum_matrix);
  srunner_add_suite(sr, sub_matrix);
  srunner_add_suite(sr, mult_number);
  srunner_add_suite(sr, mult_matrix);
  srunner_add_suite(sr, transpose);
  srunner_add_suite(sr, calc_complements);
  srunner_add_suite(sr, determinant);
  srunner_add_suite(sr, inverse_matrix);

  srunner_run_all(sr, CK_ENV);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
