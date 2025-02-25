#include "main.h"

void s21_printWideDecimal(s21_wideDecimal number) {
  for (int i = 7; i >= 0; --i) {
    s21_printBinaryInt(number.bits[i]);
  }

  printf("\n");
}

s21_wideDecimal s21_decimalToWideDecimal(s21_decimal number) {
  s21_wideDecimal wideNumber = {0};

  for (int i = 0; i < 3; ++i) {
    wideNumber.bits[i] = (unsigned)number.bits[i];
  }

  return wideNumber;
}

s21_decimal s21_WideDecimalToDecimal(s21_wideDecimal number) {
  s21_decimal result = {0};

  for (int i = 0; i < 3; ++i) {
    result.bits[i] = (int)number.bits[i];
  }

  return result;
}

s21_wideDecimal s21_wideDecimalPowerTen(s21_wideDecimal number, int power) {
  s21_wideDecimal result = number;

  for (int i = 0; i < power; ++i) {
    s21_wideDecimal valueShift3 = s21_BinaryWideshiftL(result, 3);
    s21_wideDecimal valueShift1 = s21_BinaryWideshiftL(result, 1);

    result = s21_simpleAddWideDecimal(valueShift3, valueShift1, NULL);
  }

  return result;
}

s21_wideDecimal s21_wideDecimalPowerTenDiv(s21_wideDecimal number, int power) {
  for (int divCount = 0; divCount < power; ++divCount) {
    uint64_t remain = s21_getRemain(&number);

    if (remain > 5) {
      s21_wideDecimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};
      number = s21_simpleAddWideDecimal(number, one, NULL);
    } else if (remain == 5) {
      if (s21_isSetBit(number.bits[0], 0)) {
        s21_wideDecimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};
        number = s21_simpleAddWideDecimal(number, one, NULL);
      }
    }
  }

  return number;
}  // no leaks

uint64_t s21_getRemain(s21_wideDecimal *number) {
  uint64_t remain = 0;

  for (int i = 7; i >= 0; --i) {
    uint64_t temp = ((uint64_t)remain << 32) | number->bits[i];

    number->bits[i] = (unsigned int)(temp / 10);
    remain = temp % 10;
  }

  return remain;
}

s21_wideDecimal s21_simpleAddWideDecimal(s21_wideDecimal value_1,
                                         s21_wideDecimal value_2,
                                         int *overflow) {
  int carry = 0;
  s21_wideDecimal result = {{0, 0, 0, 0, 0, 0, 0, 0}};

  for (int index = 0; index < 256; ++index) {
    int resultBit = s21_isSetBit(value_1.bits[index / 32], index % 32) +
                    s21_isSetBit(value_2.bits[index / 32], index % 32) + carry;

    carry = s21_isSetBit(resultBit, 1);

    result.bits[index / 32] |= s21_isSetBit(resultBit, 0) << index % 32;
  }

  if (overflow) *overflow = carry;

  return result;
}

s21_wideDecimal s21_simpleSubWideDecimal(s21_wideDecimal reduced,
                                         s21_wideDecimal subtrahend,
                                         int *sign) {
  s21_wideDecimal wide_result = {0};
  int overflow = 0;

  s21_invert_wideDecimal(&subtrahend);
  wide_result = s21_simpleAddWideDecimal(reduced, subtrahend, &overflow);

  if (overflow) {
    s21_wideDecimal one_wideDecimal = {{1, 0, 0, 0, 0, 0, 0, 0}};

    wide_result =
        s21_simpleAddWideDecimal(wide_result, one_wideDecimal, &overflow);

    if (sign) *sign = 0;
  } else {
    s21_invert_wideDecimal(&wide_result);

    if (sign) *sign = 1;
  }

  return wide_result;
}

s21_wideDecimal s21_simpleMulWideDecimal(s21_wideDecimal value_1,
                                         s21_wideDecimal value_2) {
  s21_wideDecimal wideResult = {0};

  for (int index = 0; index < 256; ++index) {
    if (s21_isSetBit(value_1.bits[index / 32], index % 32)) {
      s21_wideDecimal temp = s21_BinaryWideshiftL(value_2, index);
      wideResult = s21_simpleAddWideDecimal(wideResult, temp, NULL);
    }
  }

  return wideResult;
}

s21_wideDecimal s21_simpleDimple(s21_wideDecimal value_1,
                                 s21_wideDecimal value_2) {
  s21_wideDecimal wideResInt = {0};
  s21_wideDecimal wideResRemain = {0};

  for (int i = 255; i >= 0; --i) {
    wideResRemain = s21_BinaryWideshiftL(wideResRemain, 1);
    wideResRemain.bits[0] |= s21_isSetBit(value_1.bits[i / 32], i % 32);

    if (s21_greatEqualWide(wideResRemain, value_2)) {
      wideResRemain = s21_simpleSubWideDecimal(wideResRemain, value_2, NULL);

      wideResInt.bits[i / 32] |= s21_setBit(wideResInt.bits[i / 32], i % 32);
    }
  }

  return wideResInt;
}

s21_wideDecimal s21_BinaryWideshiftL(s21_wideDecimal number, int shift) {
  for (int index = 255; index >= 0; --index) {
    if (index >= shift &&
        s21_isSetBit(number.bits[(index - shift) / 32], (index - shift) % 32)) {
      number.bits[index / 32] = s21_setBit(number.bits[index / 32], index % 32);
    } else {
      number.bits[index / 32] =
          s21_resetBit(number.bits[index / 32], index % 32);
    }
  }

  return number;
}

s21_wideDecimal s21_BinaryWideshiftR(s21_wideDecimal number,
                                     int shift) {  // пока нигде не использую
  s21_wideDecimal result = number;
  int temp = 0;  // переделать на общий случай, как выше, если всё же где-то
                 // буду использовать

  for (int i = 7; i >= 0; --i) {
    int currentTemp = temp;
    temp = 0;

    for (int bits = shift - 1; bits >= 0; --bits) {
      if (s21_isSetBit(number.bits[i], bits))
        temp = s21_setBit(temp, 32 - bits - shift);
    }

    result.bits[i] >>= shift;
    result.bits[i] += currentTemp;
  }

  return result;
}

int s21_reductionToDecimal(s21_wideDecimal *number) {
  int divCount = 0;

  for (int i = 7; i > 2; --i) {
    while (number->bits[i]) {
      *number = s21_wideDecimalPowerTenDiv(*number, 1);
      ++divCount;
    }
  }

  return divCount;
}

void s21_invert_wideDecimal(s21_wideDecimal *value) {
  for (int i = 0; i < 8; i++) {
    value->bits[i] = ~(value->bits[i]);
  }
}

int s21_greatEqualWide(s21_wideDecimal value_1, s21_wideDecimal value_2) {
  int retVal = 1;

  for (int i = 7; i >= 0; --i) {
    unsigned num1 = value_1.bits[i];
    unsigned num2 = value_2.bits[i];

    if (num1 > num2) {
      break;
    } else if (num1 < num2) {
      retVal = 0;
      break;
    }
  }

  return retVal;
}