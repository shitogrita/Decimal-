#ifndef MAIN_H
#define MAIN_H

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

s21_wideDecimal s21_decimalToWideDecimal(s21_decimal);
s21_decimal s21_WideDecimalToDecimal(s21_wideDecimal);
int s21_createDecimal(s21_wideDecimal, s21_decimal *, int, int, int);
int s21_returnSign(s21_decimal, s21_decimal, int, s21_wideDecimal *);

void s21_printBinaryInt(unsigned);
int s21_isSetBit(int, int);
int s21_setBit(int, int);
int s21_resetBit(int, int);
int max(const int, const int);

int s21_is_less(s21_decimal num1, s21_decimal num2);      // del
void casting_zero(s21_decimal *num1, s21_decimal *num2);  // del
void exp_leveling(s21_decimal *num1, s21_decimal *num2);  // del

int s21_round(s21_decimal value, s21_decimal *result);  // del below
void s21_setScale(s21_decimal *value, int scale);
void s21_truncate(s21_decimal value, s21_decimal *result);
void s21_copy(s21_decimal value, s21_decimal *result);

#endif