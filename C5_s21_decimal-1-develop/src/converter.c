#include "main.h"

#define POW32 pow(2, 32)

/* краевой случай для всех: dst == 0
    по идее эту проверку делать не надо, но тогда я не знаю в каких случаях
   будет ошибка записи (1) если есть идеи, предлагайте :) */

/* краевых случаев нет */
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int res = 0;
  if (dst) {
    reset(dst);

    if (src < 0) {
      dst->bits[3] = s21_setBit(dst->bits[3], 31);
      src = abs(src);
    }
    dst->bits[0] = src;
  } else {
    res = 1;
  }
  return res;
}

/* краевые случаи:
    1е-29 и меньше
    7.9228163E28F и больше
    экспонента > 28
    числа с больше чем 7 значимыми десятичными цифрами, особенно если 8я >= 5 */
int s21_from_float_to_decimal(float src, s21_decimal *dst) {  // проверить
  int res = 0;
  double src_dbl = (double)src;
  if (fabs(src_dbl) < 1e-28) res = 1;

  if (!res && dst) {
    reset(dst);
    int sign = 0;
    if (src_dbl < 0) {
      sign = 1;
      src_dbl = fabs(src_dbl);
    }

    int exp = 0;
    int count_signific = 0;

    for (int i = 1; (int)src_dbl / i; i *= 10) {
      count_signific++;
    }

    if (count_signific > 7) {
      int over = count_signific - 7;
      double remainder = fmod(src_dbl, pow(10, over));
      if (remainder >= 5 * pow(10, over - 1)) {
        src_dbl += (pow(10, over) - remainder);
      } else {
        src_dbl -= remainder;
      }
    }

    while (fmod(src_dbl, 1) != 0 && exp < 28 && count_signific < 7) {
      src_dbl *= 10;
      if ((int)fmod(src_dbl, 10)) count_signific++;
      exp++;
    }

    if ((int)fmod(src_dbl * 10, 10) >= 5.0) src_dbl += 1;

    s21_fillFloatDecimal(src_dbl, dst, exp, sign);
  } else {
    res = 1;
  }
  return res;
}

/* некорректный децимал, то есть src.bits[3] содержит лишние биты (кроме степени
 * <= 28 и знака) */
int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int res = 0;
  if (isCorrectDecimal(src) && dst) {
    int sign = s21_getSign(src) ? -1 : 1;
    int exp = s21_getScale(src);
    *dst = ((uint32_t)src.bits[2] * POW32 * POW32 +
            (uint32_t)src.bits[1] * POW32 + (uint32_t)src.bits[0]) /
           pow(10, exp) * sign;
  } else {
    res = 1;
  }
  return res;
}

/* некорректный децимал, то есть src.bits[3] содержит лишние биты (кроме степени
 * <= 28 и знака) */
int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int res = 0;
  if (isCorrectDecimal(src) && dst) {
    int sign = s21_getSign(src) ? -1 : 1;
    int exp = s21_getScale(src);
    *dst = (double)((uint32_t)src.bits[2] * POW32 * POW32 +
                    (uint32_t)src.bits[1] * POW32 + (uint32_t)src.bits[0]) /
           pow(10, exp) * sign;
  } else {
    res = 1;
  }
  return res;
}

void reset(s21_decimal *num) {
  num->bits[0] = 0;
  num->bits[1] = 0;
  num->bits[2] = 0;
  num->bits[3] = 0;
}

int isCorrectDecimal(s21_decimal src) {
  int res = 1;
  if (src.bits[3] & 0xFFFF) {
    res = 0;
  } else if (s21_getScale(src) > 28) {
    res = 0;
  } else if (((src.bits[3] >> 24) & 0b1111111) > 0) {
    res = 0;
  } else if (s21_is_equal(src, s21_createPosInf()) ||
             s21_is_equal(src, s21_createNegInf())) {
    res = 0;
  }
  return res;
}

int s21_fillFloatDecimal(double src, s21_decimal *dst, int exp, int sign) {
  int res = 0;
  unsigned int low = fmod(src, POW32);
  unsigned int middle = fmod(src / POW32, POW32);
  unsigned int high = src / POW32 / POW32;
  unsigned int over = src / POW32 / POW32 / POW32;
  if (over != 0)
    res = 1;
  else {
    s21_initDecLMHScSign(dst, low, middle, high, exp, sign);
  }
  return res;
}