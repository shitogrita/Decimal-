#ifndef s21_WIDE_DECIMAL_H
#define s21_WIDE_DECIMAL_H

typedef struct {
  unsigned int bits[8];
} s21_wideDecimal;

void s21_printWideDecimal(s21_wideDecimal);
s21_wideDecimal s21_BinaryWideshiftL(s21_wideDecimal, int);
s21_wideDecimal s21_BinaryWideshiftR(s21_wideDecimal, int);  // ?
s21_wideDecimal s21_simpleAddWideDecimal(s21_wideDecimal, s21_wideDecimal,
                                         int *);
s21_wideDecimal s21_simpleMulWideDecimal(s21_wideDecimal, s21_wideDecimal);
s21_wideDecimal s21_simpleSubWideDecimal(s21_wideDecimal, s21_wideDecimal,
                                         int *);
s21_wideDecimal s21_simpleDimple(s21_wideDecimal, s21_wideDecimal);
s21_wideDecimal s21_wideDecimalPowerTen(s21_wideDecimal, int);
s21_wideDecimal s21_wideDecimalPowerTenDiv(s21_wideDecimal, int);
uint64_t s21_getRemain(s21_wideDecimal *);
int s21_reductionToDecimal(s21_wideDecimal *);
void s21_invert_wideDecimal(s21_wideDecimal *);
int s21_greatEqualWide(s21_wideDecimal, s21_wideDecimal);

#endif