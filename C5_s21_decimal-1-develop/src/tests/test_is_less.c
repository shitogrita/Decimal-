#include "test.h"


START_TEST(test_s21_is_less_true1) {
    s21_decimal val_1 = {{123, 0, 0, 0}};
    s21_decimal val_2 = {{0, 1, 0, 0}};
    ck_assert_int_eq(s21_is_less(val_1, val_2), 1);
} END_TEST

START_TEST(test_s21_is_less_true2) {
    s21_decimal val_1 = {{123, 0, 0, 0}};
    s21_decimal val_2 = {{0, 1, 0, 0}};
    ck_assert_int_eq(s21_is_less(val_2, val_1), 0);
} END_TEST

START_TEST(test_s21_is_less_true) {
    s21_decimal a, b;
    s21_from_int_to_decimal(5, &a);
    s21_from_int_to_decimal(10, &b);
    ck_assert_int_eq(s21_is_less(a, b), 1);
} END_TEST

START_TEST(test_s21_is_less_false) {
    s21_decimal a, b;
    s21_from_int_to_decimal(10, &a);
    s21_from_int_to_decimal(5, &b);
    ck_assert_int_eq(s21_is_less(a, b), 0);
} END_TEST

Suite *test_is_less(void) {
    Suite *s = suite_create("\033[45m-=s21_is_less=-\033[0m");
    TCase *tc_core = tcase_create("Core");
    
    tcase_add_test(tc_core, test_s21_is_less_true);
    tcase_add_test(tc_core, test_s21_is_less_true1);
    tcase_add_test(tc_core, test_s21_is_less_true2);
    tcase_add_test(tc_core, test_s21_is_less_false);
    
    suite_add_tcase(s, tc_core);
    return s;
}