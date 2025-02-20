#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

typedef struct {
  int bits[4];
} s21_decimal;

void s21_printDecimal(s21_decimal);
int s21_getSign(s21_decimal);
int s21_getScale(s21_decimal);
int s21_initDecLMHScSign(s21_decimal *, int, int, int, int, int);
int s21_fillScaleSign(s21_decimal *, int, int);
s21_decimal s21_absDecimal(s21_decimal);
s21_decimal s21_createPosInf(void);
s21_decimal s21_createNegInf(void);
s21_decimal s21_createNAN(void);
s21_decimal s21_removeTrailingZeroPoint(s21_decimal, int *);

#endif