#include "main.h"

void s21_copy(s21_decimal value, s21_decimal *result) {
  for (int i = 0; i < 4; i++) {
    result->bits[i] = value.bits[i];
  }
}
void s21_setScale(s21_decimal *value, int scale) {
  value->bits[3] &= ~(0xFF << 16);
  value->bits[3] |= (scale << 16);
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  int flag = 0;
  if (isCorrectDecimal(value) && result) {
    s21_copy(value, result);
    if (s21_isSetBit(value.bits[3], 31) == 1) {
      result->bits[3] = s21_resetBit(result->bits[3], 31);
    } else if (s21_isSetBit(value.bits[3], 31) == 0) {
      result->bits[3] = s21_setBit(result->bits[3], 31);
    }
  } else {
    flag = 1;
  }
  return flag;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int res = 0;
  if (isCorrectDecimal(value) && result) {
    int exp = s21_getScale(value);
    if (!exp) {
      for (int i = 0; i < 4; i++) {
        result->bits[i] = value.bits[i];
      }
    } else {
      float number;
      s21_from_decimal_to_float(value, &number);
      unsigned int round = number;
      s21_from_int_to_decimal(round, result);
    }
  } else {
    res = 1;
  }
  return res;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  int res = 0;
  if (isCorrectDecimal(value) && result) {
    int exp = s21_getScale(value);
    if (!exp) {
      for (int i = 0; i < 4; i++) {
        result->bits[i] = value.bits[i];
      }
    } else {
      float number;
      s21_from_decimal_to_float(value, &number);
      unsigned int round = number;
      if (number < 0) {
        round -= 1;
      }
      s21_from_int_to_decimal(round, result);
    }
  } else {
    res = 1;
  }
  return res;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  int retVal = 0;
  if (isCorrectDecimal(value) && result) {
    int scale = s21_getScale(value);
    s21_decimal temp_value = value;
    if (scale > 0) {
      s21_decimal integerPart;
      s21_copy(temp_value, &integerPart);
      s21_setScale(&integerPart, 0);

      s21_decimal fractionalPart;
      s21_copy(temp_value, &fractionalPart);
      for (int i = 0; i < scale; i++) {
        fractionalPart.bits[0] %= 10;
        integerPart.bits[0] /= 10;
      }

      if (fractionalPart.bits[0] >= 5) {
        integerPart.bits[0] += 1;
      }
      s21_copy(integerPart, result);
    } else {
      s21_copy(temp_value, result);
    }
  } else {
    retVal = 1;
  }

  return retVal;
}