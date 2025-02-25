#include "test.h"

START_TEST(test_s21_div_positive) {
    s21_decimal a, b, result;
    s21_from_int_to_decimal(10, &a);
    s21_from_int_to_decimal(5, &b);
    ck_assert_int_eq(s21_div(a, b, &result), 0);
    int converted;
    s21_from_decimal_to_int(result, &converted);
    ck_assert_int_eq(converted, 2);
} END_TEST

START_TEST(test_s21_div_negative) {
    s21_decimal a, b, result;
    s21_from_int_to_decimal(-10, &a);
    s21_from_int_to_decimal(5, &b);
    ck_assert_int_eq(s21_div(a, b, &result), 0);
    int converted;
    s21_from_decimal_to_int(result, &converted);
    ck_assert_int_eq(converted, -2);
} END_TEST

START_TEST(test_s21_div_by_zero) {
    s21_decimal a, b, result;
    s21_from_int_to_decimal(10, &a);
    s21_from_int_to_decimal(0, &b);
    ck_assert_int_eq(s21_div(a, b, &result), 3);
} END_TEST

Suite *test_div(void) {
    Suite *s = suite_create("\033[45m-=s21_div=-\033[0m");
    TCase *tc_core = tcase_create("Core");
    
    tcase_add_test(tc_core, test_s21_div_positive);
    tcase_add_test(tc_core, test_s21_div_negative);
    tcase_add_test(tc_core, test_s21_div_by_zero);
    
    suite_add_tcase(s, tc_core);
    return s;
}
