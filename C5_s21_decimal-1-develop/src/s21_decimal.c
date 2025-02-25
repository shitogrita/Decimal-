#include "main.h"

void s21_printDecimal(s21_decimal number) {
  if (1 << 31 & number.bits[3]) printf("-\n");

  for (int i = 3; i >= 0; --i) {
    s21_printBinaryInt(number.bits[i]);
  }

  printf("\n");
}

int s21_getSign(s21_decimal number) { return s21_isSetBit(number.bits[3], 31); }

int s21_getScale(s21_decimal number) { return (char)(number.bits[3] >>= 16); }

int s21_initDecLMHScSign(s21_decimal *number, int n0, int n1, int n2, int scale,
                         int sign) {
  int retVal = OK;

  number->bits[0] = n0;
  number->bits[1] = n1;
  number->bits[2] = n2;

  retVal = s21_fillScaleSign(number, scale, sign);

  return retVal;
}

int s21_fillScaleSign(s21_decimal *number, int scale, int sign) {
  int retVal = OK;

  if (scale < 0 || scale > 28) {
    if (scale < 0) {
      *number = s21_createPosInf();
      retVal = BIGNUMBER;
    } else {
      *number = s21_createNegInf();
      retVal = LOWNUMBER;
    }
  } else if (sign < 0 || sign > 1) {  // обработать ошибку
                                      // retVal = WRONGSIGN; ??
    *number = s21_createNAN();
  } else {
    sign <<= 31;
    scale <<= 16;
    number->bits[3] = scale + sign;
  }

  return retVal;
}

int s21_createDecimal(s21_wideDecimal src, s21_decimal *result, int divCount,
                      int scale, int sign) {
  int retVal = OK;

  if (divCount > scale) {
    if (!sign) {
      *result = s21_createPosInf();
      retVal = BIGNUMBER;
    } else {
      *result = s21_createNegInf();
      retVal = LOWNUMBER;
    }
  } else {
    *result = s21_WideDecimalToDecimal(src);
    *result = s21_removeTrailingZeroPoint(*result, &scale);
    s21_fillScaleSign(result, scale - divCount, sign);
    s21_negZeroToPos(result);
  }

  return retVal;
}

void s21_negZeroToPos(s21_decimal *result) {
  int k = 0;

  for (int i = 0; i < 3; ++i) {
    if (result->bits[i] == 0) ++k;
  }

  if (k == 3) result->bits[3] = s21_resetBit(result->bits[3], 31);
}

int s21_returnError(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result) {
  int retVal = OK;

  if (s21_getSign(value_1) || s21_getSign(value_2)) {
    *result = s21_createNegInf();
    retVal = LOWNUMBER;
  } else {
    *result = s21_createPosInf();
    retVal = BIGNUMBER;
  }

  return retVal;
}

int s21_checkDivZero(s21_decimal number) {
  int retVal = OK;
  char k = 0;

  for (int i = 0; i < 3; ++i) {
    if (number.bits[i] == 0) {
      ++k;
    }
  }

  if (k == 3) retVal = DIVBYZERO;

  return retVal;
}

s21_decimal s21_removeTrailingZeroPoint(s21_decimal number, int *scale) {
  s21_wideDecimal temp = s21_decimalToWideDecimal(number);

  while (!s21_getRemain(&temp) && *scale > 0) {
    number = s21_WideDecimalToDecimal(temp);
    *scale -= 1;
  }

  return number;
}

s21_decimal s21_absDecimal(s21_decimal number) {
  number.bits[3] = s21_resetBit(number.bits[3], 31);

  return number;
}

s21_decimal s21_createPosInf(void) {
  s21_decimal posInf = {{0, 0, 0, 0b00000000111111110000000000000000}};

  return posInf;
}

s21_decimal s21_createNegInf(void) {
  s21_decimal negInf = {{0, 0, 0, 0b10000000111111110000000000000000}};

  return negInf;
}

s21_decimal s21_createNAN(void) {
  s21_decimal nanNumber = {{-1, -1, -1, 0b00000000111111110000000000000000}};

  return nanNumber;
}