#include "test.h"

START_TEST(test_s21_add_positive) {
    s21_decimal a, b, result;
    s21_from_int_to_decimal(10, &a);
    s21_from_int_to_decimal(5, &b);
    ck_assert_int_eq(s21_add(a, b, &result), 0);
    int converted;
    s21_from_decimal_to_int(result, &converted);
    ck_assert_int_eq(converted, 15);
} END_TEST

START_TEST(test_s21_add_negative) {
    s21_decimal a, b, result;
    s21_from_int_to_decimal(-10, &a);
    s21_from_int_to_decimal(-5, &b);
    ck_assert_int_eq(s21_add(a, b, &result), 0);
    int converted;
    s21_from_decimal_to_int(result, &converted);
    ck_assert_int_eq(converted, -15);
} END_TEST

START_TEST(test_s21_add_zero) {
    s21_decimal a, b, result;
    s21_from_int_to_decimal(0, &a);
    s21_from_int_to_decimal(0, &b);
    ck_assert_int_eq(s21_add(a, b, &result), 0);
    int converted;
    s21_from_decimal_to_int(result, &converted);
    ck_assert_int_eq(converted, 0);
} END_TEST

Suite *test_add(void) {
    Suite *s = suite_create("\033[45m-=s21_add=-\033[0m");
    TCase *tc_core = tcase_create("Core");
    
    tcase_add_test(tc_core, test_s21_add_positive);
    tcase_add_test(tc_core, test_s21_add_negative);
    tcase_add_test(tc_core, test_s21_add_zero);
    
    suite_add_tcase(s, tc_core);
    return s;
}
