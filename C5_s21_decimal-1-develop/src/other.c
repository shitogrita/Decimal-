#include "main.h"

void s21_printBinaryInt(unsigned intNumber) {
  char result[] = "00000000 00000000 00000000 00000000";

  for (int i = 34; intNumber; --i) {
    if ((i + 1) % 9 == 0 && i) --i;

    result[i] = intNumber % 2 + '0';
    intNumber >>= 1;
  }

  printf("%s\n", result);
}

int s21_isSetBit(int number, int index) { return (number & (1 << index)) != 0; }

int s21_setBit(int number, int index) { return (number | (1 << index)); }

int s21_resetBit(int number, int index) { return (number & ~(1 << index)); }

int max(const int a, const int b) { return (a > b) ? a : b; }