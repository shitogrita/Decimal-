#include "main.h"

void casting_zero(s21_decimal* num1, s21_decimal* num2) {
  if (num1->bits[0] == 0 && num1->bits[1] == 0 && num1->bits[2] == 0) {
    *num1 = s21_absDecimal(*num1);
  }
  if (num2->bits[0] == 0 && num2->bits[1] == 0 && num2->bits[2] == 0) {
    *num2 = s21_absDecimal(*num2);
  }
}

void exp_leveling(s21_decimal* num1, s21_decimal* num2) {
  int exp1 = s21_getScale(*num1);
  int exp2 = s21_getScale(*num2);

  if (exp1 > 28) {
    // деление мантиссы num1 на 10^(exp1 - 28);
    exp1 = 28;
  }
  if (exp2 > 28) {
    // деление мантиссы num2 на 10^(exp2 - 28);
    exp2 = 28;
  }
  int exp_add = exp1 - exp2;
  if (exp_add > 0) {
    // умножение мантиссы num2 на 10^exp_add
  } else if (exp_add < 0) {
    exp_add = abs(exp_add);

    // умножение мантиссы num1 на 10^exp_add
  }
}

int s21_is_less(s21_decimal num1, s21_decimal num2) {
  casting_zero(&num1, &num2);

  int res = 0;
  int sign1 = s21_getSign(num1);
  int sign2 = s21_getSign(num2);

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

int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2) {
  casting_zero(&num1, &num2);

  int res = 0;
  int sign1 = s21_getSign(num1);
  int sign2 = s21_getSign(num2);

  if (sign1 == sign2) {
    exp_leveling(&num1, &num2);
    int match = 0;
    int out = 0;
    for (int i = 2; i >= 0 && !out; i--) {
      for (int j = 31; j >= 0 && !out; j--, match++) {
        if (!s21_isSetBit(num1.bits[i], j) && s21_isSetBit(num2.bits[i], j)) {
          res = 1;
        }
        if (s21_isSetBit(num1.bits[i], j) && !s21_isSetBit(num2.bits[i], j)) {
          out = 1;
        }
      }
    }
    if (!res) res = (match == 3 * 32);
  } else {
    res = (sign1 > sign2);
  }

  return res;
}

int s21_is_greater(s21_decimal num1, s21_decimal num2) {
  casting_zero(&num1, &num2);

  int res = 0;
  int sign1 = s21_getSign(num1);
  int sign2 = s21_getSign(num2);

  if (sign1 == sign2) {
    exp_leveling(&num1, &num2);
    for (int i = 2; i >= 0 && !res; i--) {
      for (int j = 31; j >= 0 && !res; j--) {
        if (s21_isSetBit(num1.bits[i], j) && !s21_isSetBit(num2.bits[i], j)) {
          res = 1;
        }
      }
    }
  } else {
    res = (sign1 < sign2);
  }
  return res;
}

int s21_is_greater_or_equal(s21_decimal num1, s21_decimal num2) {
  casting_zero(&num1, &num2);

  int res = 0;
  int sign1 = s21_getSign(num1);
  int sign2 = s21_getSign(num2);

  if (sign1 == sign2) {
    exp_leveling(&num1, &num2);
    int match = 0;
    for (int i = 2; i >= 0 && !res; i--) {
      for (int j = 31; j >= 0 && !res; j--, match++) {
        if (s21_isSetBit(num1.bits[i], j) && !s21_isSetBit(num2.bits[i], j)) {
          res = 1;
        }
      }
    }
    if (!res) res = (match == 3 * 32);
  } else {
    res = (sign1 < sign2);
  }

  return res;
}

int s21_is_equal(s21_decimal num1, s21_decimal num2) {
  casting_zero(&num1, &num2);

  int res = 1;
  int sign1 = s21_getSign(num1);
  int sign2 = s21_getSign(num2);

  if (sign1 == sign2) {
    exp_leveling(&num1, &num2);
    for (int i = 2; i >= 0 && res; i--) {
      for (int j = 31; j >= 0 && res; j--) {
        if (s21_isSetBit(num1.bits[i], j) != s21_isSetBit(num2.bits[i], j)) {
          res = 0;
        }
      }
    }
  } else {
    res = 0;
  }
  return res;
}

int s21_is_not_equal(s21_decimal num1, s21_decimal num2) {
  casting_zero(&num1, &num2);

  int res = 0;
  int sign1 = s21_getSign(num1);
  int sign2 = s21_getSign(num2);

  if (sign1 == sign2) {
    exp_leveling(&num1, &num2);
    for (int i = 2; i >= 0 && !res; i--) {
      for (int j = 31; j >= 0 && !res; j--) {
        if (s21_isSetBit(num1.bits[i], j) != s21_isSetBit(num2.bits[i], j)) {
          res = 1;
        }
      }
    }
  } else {
    res = 1;
  }
  return res;
}