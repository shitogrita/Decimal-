#include "main.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int retVal = OK;
  int scale_1 = s21_getScale(value_1);
  int scale_2 = s21_getScale(value_2);

  if (scale_1 == -1 || scale_2 == -1) {
    retVal = s21_returnError(value_1, value_2, result);
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
      wideResult = s21_simpleAddWideDecimal(wideValue_1, wideValue_2, NULL);
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
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int retVal = OK;
  int scale_1 = s21_getScale(value_1);
  int scale_2 = s21_getScale(value_2);

  if (scale_1 == -1 || scale_2 == -1) {
    retVal = s21_returnError(value_1, value_2, result);
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
    *result =
        s21_simpleSubWideDecimal(wide_value_2, wide_value_1, &result_sign);
  } else {
    *result =
        s21_simpleSubWideDecimal(wide_value_1, wide_value_2, &result_sign);
  }

  return result_sign;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int retVal = OK;
  int scale_1 = s21_getScale(value_1);
  int scale_2 = s21_getScale(value_2);

  if (scale_1 == -1 || scale_2 == -1) {
    retVal = s21_returnError(value_1, value_2, result);
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
  }

  return retVal;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int retVal = OK;
  int scale_1 = s21_getScale(value_1);
  int scale_2 = s21_getScale(value_2);

  if (scale_1 == -1 || scale_2 == -1) {
    retVal = s21_returnError(value_1, value_2, result);
  } else if ((retVal = s21_checkDivZero(value_2)) != 3) {
    int diffScale = abs(scale_1 - scale_2);
    int sign_1 = s21_getSign(value_1);
    int sign_2 = s21_getSign(value_2);

    s21_wideDecimal wideValue_1 = s21_decimalToWideDecimal(value_1);
    s21_wideDecimal wideValue_2 = s21_decimalToWideDecimal(value_2);

    if (scale_1 < scale_2) {
      wideValue_1 = s21_wideDecimalPowerTen(wideValue_1, diffScale);
    } else {
      wideValue_2 = s21_wideDecimalPowerTen(wideValue_2, diffScale);
    }

    wideValue_1 = s21_wideDecimalPowerTen(wideValue_1, 20);

    s21_wideDecimal wideResInt = s21_simpleDimple(wideValue_1, wideValue_2);

    int divCount = s21_reductionToDecimal(&wideResInt);
    retVal =
        s21_createDecimal(wideResInt, result, divCount, 20, sign_1 ^ sign_2);
  }

  return retVal;
}
