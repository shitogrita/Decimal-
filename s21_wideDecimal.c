#include "main.h"

void s21_printWideDecimal(s21_wideDecimal number) {
  for (int i = 7; i >= 0; --i) {
    s21_printBinaryInt(number.bits[i]);
  }

  printf("\n");
}  // старшие -> младшие // no leaks

s21_wideDecimal s21_decimalToWideDecimal(s21_decimal number) {
  s21_wideDecimal wideNumber = {{0, 0, 0, 0, 0, 0, 0, 0}};

  for (int i = 0; i < 3; ++i) {
    wideNumber.bits[i] = (unsigned)number.bits[i];
  }

  return wideNumber;
}  // no leaks

s21_decimal s21_WideDecimalToDecimal(s21_wideDecimal number) {
  s21_decimal result = {{0, 0, 0, 0}};

  for (int i = 0; i < 3; ++i) {
    result.bits[i] = (int)number.bits[i];
  }

  return result;
}  // no leaks

s21_wideDecimal s21_wideDecimalPowerTen(s21_wideDecimal number, int power) {
  s21_wideDecimal result = number;

  for (int i = 0; i < power; ++i) {
    s21_wideDecimal valueShift3 = s21_BinaryWideshiftL(result, 3);
    s21_wideDecimal valueShift1 = s21_BinaryWideshiftL(result, 1);

    result = s21_simpleAddWideDecimal(valueShift3, valueShift1);
  }

  return result;
}

s21_wideDecimal s21_wideDecimalPowerTenDiv(s21_wideDecimal number, int power) {
  for (int divCount = 0; divCount < power; ++divCount) {
    uint64_t remain = s21_getRemain(&number);

    if (remain > 5) {
      s21_wideDecimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};
      number = s21_simpleAddWideDecimal(number, one);
    } else if (remain == 5) {
      if (s21_isSetBit(number.bits[0], 0)) {
        s21_wideDecimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};
        number = s21_simpleAddWideDecimal(number, one);
      }
    }
  }

  return number;
}  // no leaks

uint64_t s21_getRemain(s21_wideDecimal *number) {  // может функция и не нужна
  uint64_t remain = 0;

  for (int i = 7; i >= 0; --i) {
    uint64_t temp = ((uint64_t)remain << 32) | number->bits[i];

    number->bits[i] = (unsigned int)(temp / 10);
    remain = temp % 10;
  }

  return remain;
}

s21_wideDecimal s21_simpleAddWideDecimal(s21_wideDecimal value_1,
                                         s21_wideDecimal value_2) {
  int carry = 0;
  s21_wideDecimal result = {{0, 0, 0, 0, 0, 0, 0, 0}};

  for (int index = 0; index < 256; ++index) {
    int resultBit = s21_isSetBit(value_1.bits[index / 32], index % 32) +
                    s21_isSetBit(value_2.bits[index / 32], index % 32) + carry;

    carry = s21_isSetBit(resultBit, 1);

    result.bits[index / 32] |= s21_isSetBit(resultBit, 0) << index % 32;
  }

  return result;
}  // no leaks

s21_wideDecimal s21_simpleMulWideDecimal(s21_wideDecimal value_1,
                                         s21_wideDecimal value_2) {
  s21_wideDecimal wideResult = {{0, 0, 0, 0, 0, 0, 0, 0}};

  for (int index = 0; index < 256; ++index) {
    if (s21_isSetBit(value_1.bits[index / 32], index % 32)) {
      s21_wideDecimal temp = s21_BinaryWideshiftL(value_2, index);
      wideResult = s21_simpleAddWideDecimal(wideResult, temp);
    }
  }

  return wideResult;
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
}  // no leaks

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