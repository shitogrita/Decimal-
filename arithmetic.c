#include "main.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int scale_1 = s21_getScale(value_1);
  int scale_2 = s21_getScale(value_2);
  int retVal = OK;

  if (scale_1 == -1 || scale_2 == -1) {
    *result = s21_createNAN();
    retVal = BIGNUMBER;
  } else {
    int sign_1 = s21_getSign(value_1);
    int sign_2 = s21_getSign(value_2);
    int diffScale = abs(scale_1 - scale_2);

    s21_wideDecimal wideValue_1 = s21_decimalToWideDecimal(value_1);
    s21_wideDecimal wideValue_2 = s21_decimalToWideDecimal(value_2);

    if (scale_1 < scale_2) {
      wideValue_1 = s21_wideDecimalPowerTen(wideValue_1, diffScale);
    } else {
      wideValue_2 = s21_wideDecimalPowerTen(wideValue_2, diffScale);
    }

    s21_wideDecimal wideResult = {0};

    if (sign_1 == sign_2) {
      wideResult = s21_simpleAddWideDecimal(wideValue_1, wideValue_2);
      int divCount = s21_reductionToDecimal(&wideResult);
      int maxScale = max(scale_1, scale_2);
      retVal =
          s21_createDecimal(wideResult, result, divCount, maxScale, sign_1);
    } else {
      value_2.bits[3] ^= (1 << 31);
      retVal = s21_sub(value_1, value_2, result);
    }
  }

  return retVal;
}  // +

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int retVal = OK;
  int scale_1 = s21_getScale(value_1);
  int scale_2 = s21_getScale(value_2);

  if (scale_1 == -1 || scale_2 == -1) {
    *result = s21_createNAN();
    retVal = BIGNUMBER;
  } else {
    int sign1 = s21_getSign(value_1);
    int sign2 = s21_getSign(value_2);

    if (sign1 == sign2) {
      s21_wideDecimal wide_result = {0};

      int sign = s21_returnSign(value_1, value_2, sign1, &wide_result);
      int divCount = s21_reductionToDecimal(&wide_result);
      int maxScale = max(scale_1, scale_2);

      retVal = s21_createDecimal(wide_result, result, divCount, maxScale, sign);
    } else {
      value_2.bits[3] ^= (1 << 31);
      retVal = s21_add(value_1, value_2, result);
    }
  }

  return retVal;
}

s21_wideDecimal s21_simpleSubWideDecimal(s21_wideDecimal value_min,
                                         s21_wideDecimal value_max) {
  s21_wideDecimal wide_result = {0};

  // s21_printWideDecimal(value_max);
  s21_invert_wideDecimal(&value_max);
  // s21_printWideDecimal(value_max);

  wide_result = s21_simpleAddWideDecimal(value_min, value_max);
  s21_invert_wideDecimal(&wide_result);

  return wide_result;
}

int s21_returnSign(s21_decimal value_1, s21_decimal value_2, int sign1,
                   s21_wideDecimal *result) {
  int scale_1 = s21_getScale(value_1);
  int scale_2 = s21_getScale(value_2);
  int diffScale = abs(scale_1 - scale_2);

  s21_wideDecimal wide_value_1 = s21_decimalToWideDecimal(value_1);
  s21_wideDecimal wide_value_2 = s21_decimalToWideDecimal(value_2);

  if (scale_1 < scale_2) {
    wide_value_1 = s21_wideDecimalPowerTen(wide_value_1, diffScale);
  } else {
    wide_value_2 = s21_wideDecimalPowerTen(wide_value_2, diffScale);
  }

  int result_sign = -1;

  if (sign1) {
    if (s21_is_less(value_1, value_2)) {
      *result = s21_simpleSubWideDecimal(wide_value_1, wide_value_2);
      result_sign = 0;
    } else {
      *result = s21_simpleSubWideDecimal(wide_value_2, wide_value_1);
      result_sign = 1;
    }
  } else {
    if (s21_is_less(value_1, value_2)) {
      *result = s21_simpleSubWideDecimal(wide_value_1, wide_value_2);
      result_sign = 1;
    } else {
      *result = s21_simpleSubWideDecimal(wide_value_2, wide_value_1);
      result_sign = 0;
    }
  }

  return result_sign;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int scale_1 = s21_getScale(value_1);
  int scale_2 = s21_getScale(value_2);
  int retVal = OK;

  if (scale_1 == -1 || scale_2 == -1) {
    *result = s21_createNAN();
    retVal = BIGNUMBER;
  } else {
    int sign_1 = s21_getSign(value_1);
    int sign_2 = s21_getSign(value_2);
    int diffScale = abs(scale_1 - scale_2);
    s21_wideDecimal wideValue_1 = s21_decimalToWideDecimal(value_1);
    s21_wideDecimal wideValue_2 = s21_decimalToWideDecimal(value_2);

    if (scale_1 < scale_2) {
      wideValue_1 = s21_wideDecimalPowerTen(wideValue_1, diffScale);
    } else {
      wideValue_2 = s21_wideDecimalPowerTen(wideValue_2, diffScale);
    }

    s21_wideDecimal wideResult = {0};

    wideResult = s21_simpleMulWideDecimal(wideValue_1, wideValue_2);
    wideResult = s21_wideDecimalPowerTenDiv(wideResult, diffScale);
    int divCount = s21_reductionToDecimal(&wideResult);
    retVal = s21_createDecimal(wideResult, result, divCount, scale_1 + scale_2,
                               sign_1 ^ sign_2);

    s21_printWideDecimal(wideResult);
  }

  return retVal;
}  // +

// int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
//   int retVal = OK;

//   if ((retVal = s21_checkDivZero(value_2)) != 3) {
//     int scale_1 = s21_getScale(value_1);
//     int scale_2 = s21_getScale(value_2);
//     int sign_1 = s21_getSign(value_1);
//     int sign_2 = s21_getSign(value_2);
//     int diffScale = abs(scale_1 - scale_2);
//     s21_wideDecimal wideValue_1 = s21_decimalToWideDecimal(value_1);
//     s21_wideDecimal wideValue_2 = s21_decimalToWideDecimal(value_2);

//     if (scale_1 < scale_2) {
//       wideValue_1 = s21_wideDecimalPowerTen(wideValue_1, diffScale);
//     } else {
//       wideValue_2 = s21_wideDecimalPowerTen(wideValue_2, diffScale);
//     }

//     int signPrev = sign_1;
//     int signCur = sign_1;
//     s21_wideDecimal R = wideValue_1;
//     s21_wideDecimal Rprev = R;
//     s21_wideDecimal wideResult = {0};

//     for (int i = 255; i >= 0; --i) {
//       wideValue_1 = s21_BinaryWideshiftL(wideValue_1, 1);

//       if (signPrev) {
//         Rprev = s21_simpleAddWideDecimal(R, wideValue_2);
//       } else {
//         Rprev = s21_simpleSubWideDecimal(R, wideValue_2);
//       }

//       if ()
//     }
//   }

//   return retVal;
// }

// int s21_checkDivZero(s21_decimal number) {
//   int retVal = OK;
//   char k = 0;

//   for (int i = 0; i < 3; ++i) {
//     if (number.bits[i] == 0) {
//       ++k;
//     }
//   }

//   if (k == 3) retVal = DIVBYZERO;

//   return retVal;
// }

int s21_is_less(s21_decimal num1, s21_decimal num2) {
  casting_zero(&num1, &num2);

  int res = 0;
  int sign1 = s21_isSetBit(num1.bits[3], 31);
  int sign2 = s21_isSetBit(num2.bits[3], 31);

  if (sign1 == sign2) {
    exp_leveling(&num1, &num2);
    int out = 0;
    for (int i = 2; i >= 0 && !out; i--) {
      for (int j = 31; j >= 0 && !out; j--) {
        if (!s21_isSetBit(num1.bits[i], j) && s21_isSetBit(num2.bits[i], j)) {
          res = 1;
        }
        if (s21_isSetBit(num1.bits[i], j) && !s21_isSetBit(num2.bits[i], j)) {
          out = 1;
        }
      }
    }
  } else {
    res = (sign1 > sign2);
  }
  return res;
}

void casting_zero(s21_decimal *num1, s21_decimal *num2) {
  if (num1->bits[0] == 0 && num1->bits[1] == 0 && num1->bits[2] == 0) {
    num1->bits[3] = s21_resetBit(num1->bits[3], 31);
  }
  if (num2->bits[0] == 0 && num2->bits[1] == 0 && num2->bits[2] == 0) {
    num1->bits[3] = s21_resetBit(num2->bits[3], 31);
  }
}

void exp_leveling(s21_decimal *num1, s21_decimal *num2) {
  int exp1 = s21_getScale(*num1);
  int exp2 = s21_getScale(*num2);

  // if (exp1 > 28) {
  //   // деление мантиссы num1 на 10^(exp1 - 28);
  //   exp1 = 28;
  // }
  // if (exp2 > 28) {
  //   // деление мантиссы num2 на 10^(exp2 - 28);
  //   exp2 = 28;
  // }
  int exp_add = exp1 - exp2;
  if (exp_add > 0) {
    // умножение мантиссы num2 на 10^exp_add
  } else if (exp_add < 0) {
    exp_add = abs(exp_add);

    // умножение мантиссы num1 на 10^exp_add
  }
}
