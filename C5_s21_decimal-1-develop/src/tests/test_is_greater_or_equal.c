#include "test.h"

START_TEST(test_s21_is_greater_or_equal_true) {
    s21_decimal a, b;
    s21_from_int_to_decimal(10, &a);
    s21_from_int_to_decimal(5, &b);
    ck_assert_int_eq(s21_is_greater_or_equal(a, b), 1);
} END_TEST

START_TEST(test_s21_is_greater_or_equal_equal) {
    s21_decimal a, b;
    s21_from_int_to_decimal(7, &a);
    s21_from_int_to_decimal(7, &b);
    ck_assert_int_eq(s21_is_greater_or_equal(a, b), 1);
} END_TEST

START_TEST(test_s21_is_greater_or_equal_false) {
    s21_decimal a, b;
    s21_from_int_to_decimal(-5, &a);
    s21_from_int_to_decimal(10, &b);
    ck_assert_int_eq(s21_is_greater_or_equal(a, b), 0);
} END_TEST

Suite *test_is_greater_or_equal(void) {
    Suite *s = suite_create("\033[45m-=s21_is_greater_or_equal=-\033[0m");
    TCase *tc_core = tcase_create("Core");
    
    tcase_add_test(tc_core, test_s21_is_greater_or_equal_true);
    tcase_add_test(tc_core, test_s21_is_greater_or_equal_equal);
    tcase_add_test(tc_core, test_s21_is_greater_or_equal_false);
    
    suite_add_tcase(s, tc_core);
    return s;
}