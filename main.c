#include "main.h"

int main(void) {
  // s21_wideDecimal num10 = {{1, 0, 0, 0, 1, 0, 0, 0}};
  // s21_printWideDecimal(s21_BinaryWideshiftL(num10, 256));

  // s21_wideDecimal wDec = {{100, 0, 0, 0, 0, 0, 0, 0}};
  // s21_printWideDecimal(s21_wideDecimalPowerTenDiv(wDec, 20));

  s21_decimal num1;
  // s21_decimal num2;
  s21_decimal result;

  // еще нужны тесты на правильность возвращаемого значения из функции (0, 1, 2,
  // 3)
#ifdef ROUND
  printf("round 1\n");
  s21_initDecLMHScSign(&num1, 150, 0, 0, 2, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);

  s21_round(num1, &result);
  s21_printDecimal(result);
#endif

#ifdef ADD
  printf("base add\n");
  s21_initDecLMHScSign(&num1, 1, 0, 0, 0, 0);
  s21_initDecLMHScSign(&num2, 1, 0, 0, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_add(num1, num2, &result);
  s21_printDecimal(result);

  printf("base neg add\n");
  s21_initDecLMHScSign(&num1, 1, 0, 0, 0, 1);
  s21_initDecLMHScSign(&num2, 1, 0, 0, 0, 1);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_add(num1, num2, &result);
  s21_printDecimal(result);

  printf("base +- add\n");
  s21_initDecLMHScSign(&num1, 1, 0, 0, 0, 0);
  s21_initDecLMHScSign(&num2, 2, 0, 0, 0, 1);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_add(num1, num2, &result);
  s21_printDecimal(result);

  printf("base -+ add\n");
  s21_initDecLMHScSign(&num1, 1, 0, 0, 0, 1);
  s21_initDecLMHScSign(&num2, 2, 0, 0, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_add(num1, num2, &result);
  s21_printDecimal(result);

  printf("add max neg max\n");
  s21_initDecLMHScSign(&num1, -1, -1, -1, 0, 0);
  s21_initDecLMHScSign(&num2, -1, -1, -1, 0, 1);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_add(num1, num2, &result);
  s21_printDecimal(result);

  printf("add neg max max\n");
  s21_initDecLMHScSign(&num1, -1, -1, -1, 0, 1);
  s21_initDecLMHScSign(&num2, -1, -1, -1, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_add(num1, num2, &result);
  s21_printDecimal(result);

  printf("add two pos max\n");
  s21_initDecLMHScSign(&num1, -1, -1, -1, 0, 0);
  s21_initDecLMHScSign(&num2, -1, -1, -1, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_add(num1, num2, &result);
  s21_printDecimal(result);

  printf("add two neg max\n");
  s21_initDecLMHScSign(&num1, -1, -1, -1, 0, 1);
  s21_initDecLMHScSign(&num2, -1, -1, -1, 0, 1);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_add(num1, num2, &result);
  s21_printDecimal(result);

  printf("add two pos small\n");
  s21_initDecLMHScSign(&num1, 1, 0, 0, 28, 0);
  s21_initDecLMHScSign(&num2, 1, 0, 0, 28, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_add(num1, num2, &result);
  s21_printDecimal(result);

  printf("close to big number\n");
  s21_initDecLMHScSign(&num1, -6, -1, -1, 0, 0);
  s21_initDecLMHScSign(&num2, 275, 0, 0, 2, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_add(num1, num2, &result);
  s21_printDecimal(result);

  printf("add 1 & small\n");
  s21_initDecLMHScSign(&num1, 1, 0, 0, 0, 0);
  s21_initDecLMHScSign(&num2, 1, 0, 0, 28, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_add(num1, num2, &result);
  s21_printDecimal(result);

  printf("add 0.1 + 0.9 = 1, scale = 0\n");
  s21_initDecLMHScSign(&num1, 1, 0, 0, 1, 0);
  s21_initDecLMHScSign(&num2, 9, 0, 0, 1, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_add(num1, num2, &result);
  s21_printDecimal(result);

  printf("add NAN\n");
  s21_initDecLMHScSign(&num1, 1, 0, 0, 30, 0);
  s21_initDecLMHScSign(&num2, 1, 0, 0, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_add(num1, num2, &result);
  s21_printDecimal(result);
#endif
#ifdef MUL
  printf("base mul ++ 1\n");
  s21_initDecLMHScSign(&num1, 45, 0, 0, 0, 0);
  s21_initDecLMHScSign(&num2, 6, 0, 0, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_mul(num1, num2, &result);
  s21_printDecimal(result);

  printf("base mul ++ 2\n");
  s21_initDecLMHScSign(&num1, 151, 0, 0, 0, 0);
  s21_initDecLMHScSign(&num2, 24, 0, 0, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_mul(num1, num2, &result);
  s21_printDecimal(result);

  printf("base mul --\n");
  s21_initDecLMHScSign(&num1, 45, 0, 0, 0, 1);
  s21_initDecLMHScSign(&num2, 6, 0, 0, 0, 1);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_mul(num1, num2, &result);
  s21_printDecimal(result);

  printf("base mul -+\n");
  s21_initDecLMHScSign(&num1, 45, 0, 0, 0, 1);
  s21_initDecLMHScSign(&num2, 6, 0, 0, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_mul(num1, num2, &result);
  s21_printDecimal(result);

  printf("base mul +-\n");
  s21_initDecLMHScSign(&num1, 45, 0, 0, 0, 0);
  s21_initDecLMHScSign(&num2, 6, 0, 0, 0, 1);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_mul(num1, num2, &result);
  s21_printDecimal(result);

  printf("diff scale 4.5 * 6\n");
  s21_initDecLMHScSign(&num1, 45, 0, 0, 1, 0);
  s21_initDecLMHScSign(&num2, 6, 0, 0, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_mul(num1, num2, &result);
  s21_printDecimal(result);

  printf("diff scale 0.45 * 6\n");
  s21_initDecLMHScSign(&num1, 45, 0, 0, 2, 0);
  s21_initDecLMHScSign(&num2, 6, 0, 0, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_mul(num1, num2, &result);
  s21_printDecimal(result);

  printf("diff scale 0.45 * 0.6\n");
  s21_initDecLMHScSign(&num1, 45, 0, 0, 2, 0);
  s21_initDecLMHScSign(&num2, 6, 0, 0, 1, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_mul(num1, num2, &result);
  s21_printDecimal(result);

  printf("mul two max ++\n");
  s21_initDecLMHScSign(&num1, -1, -1, -1, 0, 0);
  s21_initDecLMHScSign(&num2, -1, -1, -1, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_mul(num1, num2, &result);
  s21_printDecimal(result);

  printf("mul two max --\n");
  s21_initDecLMHScSign(&num1, -1, -1, -1, 0, 1);
  s21_initDecLMHScSign(&num2, -1, -1, -1, 0, 1);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_mul(num1, num2, &result);
  s21_printDecimal(result);

  printf("mul two max +-\n");
  s21_initDecLMHScSign(&num1, -1, -1, -1, 0, 1);
  s21_initDecLMHScSign(&num2, -1, -1, -1, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_mul(num1, num2, &result);
  s21_printDecimal(result);

  printf("mul two max scale 28\n");
  s21_initDecLMHScSign(&num1, -1, -1, -1, 28, 0);
  s21_initDecLMHScSign(&num2, -1, -1, -1, 28, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_mul(num1, num2, &result);
  s21_printDecimal(result);

  printf("mul min scale 28\n");
  s21_initDecLMHScSign(&num1, 1, 0, 0, 28, 0);
  s21_initDecLMHScSign(&num2, 1, 0, 0, 28, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_mul(num1, num2, &result);
  s21_printDecimal(result);

  printf("mul nan\n");
  s21_initDecLMHScSign(&num1, -1, -1, -1, 30, 0);
  s21_initDecLMHScSign(&num2, -1, -1, -1, 28, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_mul(num1, num2, &result);
  s21_printDecimal(result);
#endif

#ifdef SUB
  printf("base sub 1\n");
  s21_initDecLMHScSign(&num1, 2, 0, 0, 0, 0);
  s21_initDecLMHScSign(&num2, 1, 0, 0, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_sub(num1, num2, &result);
  s21_printDecimal(result);

  printf("base sub 2\n");
  s21_initDecLMHScSign(&num1, 1, 0, 0, 0, 0);
  s21_initDecLMHScSign(&num2, 2, 0, 0, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_sub(num1, num2, &result);
  s21_printDecimal(result);

  printf("edge case max - 0.6\n");
  s21_initDecLMHScSign(&num1, -1, -1, -1, 0, 0);
  s21_initDecLMHScSign(&num2, 6, 0, 0, 1, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_sub(num1, num2, &result);
  s21_printDecimal(result);

  printf("sub two pos max\n");
  s21_initDecLMHScSign(&num1, -1, -1, -1, 0, 0);
  s21_initDecLMHScSign(&num2, -1, -1, -1, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_sub(num1, num2, &result);
  s21_printDecimal(result);

  printf("sub two neg max\n");
  s21_initDecLMHScSign(&num1, -1, -1, -1, 0, 1);
  s21_initDecLMHScSign(&num2, -1, -1, -1, 0, 1);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_sub(num1, num2, &result);
  s21_printDecimal(result);

  printf("sub max neg max\n");
  s21_initDecLMHScSign(&num1, -1, -1, -1, 0, 0);
  s21_initDecLMHScSign(&num2, -1, -1, -1, 0, 1);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_sub(num1, num2, &result);
  s21_printDecimal(result);

  printf("sub neg max max\n");
  s21_initDecLMHScSign(&num1, -1, -1, -1, 0, 1);
  s21_initDecLMHScSign(&num2, -1, -1, -1, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_sub(num1, num2, &result);
  s21_printDecimal(result);

  printf("sub max small\n");
  s21_initDecLMHScSign(&num1, 1, 0, 0, 28, 0);
  s21_initDecLMHScSign(&num2, 2, 0, 0, 28, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_sub(num1, num2, &result);
  s21_printDecimal(result);

  printf("close to big number\n");
  s21_initDecLMHScSign(&num1, -6, -1, -1, 0, 0);
  s21_initDecLMHScSign(&num2, 275, 0, 0, 2, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_sub(num1, num2, &result);
  s21_printDecimal(result);

  printf("sub small & big\n");  // из-за недописанного is_less перепроверить
  s21_initDecLMHScSign(&num1, 1, 0, 0, 28, 0);
  s21_initDecLMHScSign(&num2, 1, 0, 0, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_sub(num1, num2, &result);
  s21_printDecimal(result);

  printf("sub 0.1 - 0.9 = -0.8, scale = 0\n");
  s21_initDecLMHScSign(&num1, 1, 0, 0, 1, 0);
  s21_initDecLMHScSign(&num2, 9, 0, 0, 1, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_sub(num1, num2, &result);
  s21_printDecimal(result);

  printf("sub NAN\n");
  s21_initDecLMHScSign(&num1, 1, 0, 0, 30, 0);
  s21_initDecLMHScSign(&num2, 1, 0, 0, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_sub(num1, num2, &result);
  s21_printDecimal(result);

#endif

#ifdef DIV

#endif

  return 0;
}