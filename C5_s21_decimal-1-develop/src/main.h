#ifndef MAIN_H_
#define MAIN_H_

#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_decimal.h"
#include "s21_wideDecimal.h"

enum errors {
  OK = 0,
  BIGNUMBER = 1,
  LOWNUMBER = 2,
  DIVBYZERO = 3,
};

int s21_add(s21_decimal, s21_decimal, s21_decimal *);
int s21_sub(s21_decimal, s21_decimal, s21_decimal *);
int s21_mul(s21_decimal, s21_decimal, s21_decimal *);
int s21_div(s21_decimal, s21_decimal, s21_decimal *);

int s21_returnError(s21_decimal, s21_decimal, s21_decimal *);
int s21_checkDivZero(s21_decimal);

s21_wideDecimal s21_decimalToWideDecimal(s21_decimal);
s21_decimal s21_WideDecimalToDecimal(s21_wideDecimal);
int s21_createDecimal(s21_wideDecimal, s21_decimal *, int, int, int);
int s21_returnSign(s21_decimal, s21_decimal, int, s21_wideDecimal *);

void s21_printBinaryInt(unsigned);
int s21_isSetBit(int, int);
int s21_setBit(int, int);
int s21_resetBit(int, int);
int max(const int, const int);

int s21_is_less(s21_decimal num1, s21_decimal num2);
int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2);
int s21_is_greater(s21_decimal num1, s21_decimal num2);
int s21_is_greater_or_equal(s21_decimal num1, s21_decimal num2);
int s21_is_equal(s21_decimal num1, s21_decimal num2);
int s21_is_not_equal(s21_decimal num1, s21_decimal num2);
void casting_zero(s21_decimal *num1, s21_decimal *num2);
void exp_leveling(s21_decimal *num1, s21_decimal *num2);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
void reset(s21_decimal *num);
int isCorrectDecimal(s21_decimal src);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
void reset(s21_decimal *num);
int isCorrectDecimal(s21_decimal src);
int s21_fillFloatDecimal(double src, s21_decimal *dst, int exp, int sign);

int s21_negate(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);

#endif