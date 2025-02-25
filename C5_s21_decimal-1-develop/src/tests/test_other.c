#include "test.h"

START_TEST(test_s21_floor_positive) {
    s21_decimal value, result;
    s21_from_float_to_decimal(5.7, &value);
    ck_assert_int_eq(s21_floor(value, &result), 0);
    int converted;
    s21_from_decimal_to_int(result, &converted);
    ck_assert_int_eq(converted, 5);
} END_TEST

START_TEST(test_s21_floor_negative) {
    s21_decimal value, result;
    s21_from_float_to_decimal(-5.7, &value);
    ck_assert_int_eq(s21_floor(value, &result), 0);
    int converted;
    s21_from_decimal_to_int(result, &converted);
    ck_assert_int_eq(converted, -6);
} END_TEST

START_TEST(test_s21_round_positive) {
    s21_decimal value, result;
    s21_from_float_to_decimal(5.5, &value);
    ck_assert_int_eq(s21_round(value, &result), 0);
    int converted;
    s21_from_decimal_to_int(result, &converted);
    ck_assert_int_eq(converted, 6);
} END_TEST

START_TEST(test_s21_round_negative) {
    s21_decimal value, result;
    s21_from_float_to_decimal(-5.5, &value);
    ck_assert_int_eq(s21_round(value, &result), 0);
    int converted;
    s21_from_decimal_to_int(result, &converted);
    ck_assert_int_eq(converted, -6);
} END_TEST

START_TEST(test_s21_truncate) {
    s21_decimal value, result;
    s21_from_float_to_decimal(5.9, &value);
    ck_assert_int_eq(s21_truncate(value, &result), 0);
    int converted;
    s21_from_decimal_to_int(result, &converted);
    ck_assert_int_eq(converted, 5);
} END_TEST

START_TEST(test_s21_negate) {
    s21_decimal value, result;
    s21_from_int_to_decimal(5, &value);
    ck_assert_int_eq(s21_negate(value, &result), 0);
    int converted;
    s21_from_decimal_to_int(result, &converted);
    ck_assert_int_eq(converted, -5);
} END_TEST

Suite *test_other(void) {
    Suite *s = suite_create("\033[45m-=s21_other=-\033[0m");
    TCase *tc_core = tcase_create("Core");
    
    tcase_add_test(tc_core, test_s21_floor_positive);
    tcase_add_test(tc_core, test_s21_floor_negative);
    tcase_add_test(tc_core, test_s21_round_positive);
    tcase_add_test(tc_core, test_s21_round_negative);
    tcase_add_test(tc_core, test_s21_truncate);
    tcase_add_test(tc_core, test_s21_negate);
    
    suite_add_tcase(s, tc_core);
    return s;
}