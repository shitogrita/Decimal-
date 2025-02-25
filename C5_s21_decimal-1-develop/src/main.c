#include "main.h"

int main(void) {
  s21_decimal num1;
  s21_decimal num2;
  s21_decimal result;

  // еще нужны тесты на правильность возвращаемого значения из функции (0, 1, 2,
  // 3)

#ifdef DIV
  printf("int div 10 / 5\n");
  s21_initDecLMHScSign(&num1, 10, 0, 0, 0, 0);
  s21_initDecLMHScSign(&num2, 5, 0, 0, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_div(num1, num2, &result);
  s21_printDecimal(result);

  printf("10 / 4 = 2.5\n");
  s21_initDecLMHScSign(&num1, 10, 0, 0, 0, 0);
  s21_initDecLMHScSign(&num2, 4, 0, 0, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_div(num1, num2, &result);
  s21_printDecimal(result);

  printf("10 / 8 = 1.25\n");
  s21_initDecLMHScSign(&num1, 10, 0, 0, 0, 0);
  s21_initDecLMHScSign(&num2, 8, 0, 0, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_div(num1, num2, &result);
  s21_printDecimal(result);

  printf("0.1 / 8\n");
  s21_initDecLMHScSign(&num1, 1, 0, 0, 1, 0);
  s21_initDecLMHScSign(&num2, 8, 0, 0, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_div(num1, num2, &result);
  s21_printDecimal(result);

  printf("0.15 / 0.3 = 0.5\n");
  s21_initDecLMHScSign(&num1, 15, 0, 0, 2, 0);
  s21_initDecLMHScSign(&num2, 3, 0, 0, 1, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_div(num1, num2, &result);
  s21_printDecimal(result);

  printf("1 / 0 = error\n");
  s21_initDecLMHScSign(&num1, 1, 0, 0, 0, 0);
  s21_initDecLMHScSign(&num2, 0, 0, 0, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  printf("error = 3 = %d\n", s21_div(num1, num2, &result));
  s21_printDecimal(result);

  printf("max / 1 = max\n");
  s21_initDecLMHScSign(&num1, -1, -1, -1, 0, 0);
  s21_initDecLMHScSign(&num2, 1, 0, 0, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_div(num1, num2, &result);
  s21_printDecimal(result);

  printf("max / 2\n");
  s21_initDecLMHScSign(&num1, -1, -1, -1, 0, 0);
  s21_initDecLMHScSign(&num2, 2, 0, 0, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_div(num1, num2, &result);
  s21_printDecimal(result);

  printf("7 / 3\n");
  s21_initDecLMHScSign(&num1, 7, 0, 0, 18, 0);
  s21_initDecLMHScSign(&num2, 3, 0, 0, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_div(num1, num2, &result);
  s21_printDecimal(result);

  printf("int div -10 / 5\n");
  s21_initDecLMHScSign(&num1, 10, 0, 0, 0, 1);
  s21_initDecLMHScSign(&num2, 5, 0, 0, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_div(num1, num2, &result);
  s21_printDecimal(result);

#endif

#ifdef ADD
  printf("base add\n");
  s21_initDecLMHScSign(&num1, 1, 0, 0, 0, 0);
  s21_initDecLMHScSign(&num2, 1, 0, 0, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  float res = 0;
  // float example = 1e-28;
  // int res2 = 0;
  // int i = s21_from_float_to_decimal(example, &num2);
  // printf("%d\n", i);
  // s21_printDecimal(num2);
  // printf("%.8f\n", example);
  s21_from_decimal_to_float(num2, &res);
  printf("%.8f\n", res);
  // s21_from_decimal_to_int(num2, &res2);
  // printf("%d\n", res2);

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

  printf("add 0.15 + 0.3\n");
  s21_initDecLMHScSign(&num1, 15, 0, 0, 2, 0);
  s21_initDecLMHScSign(&num2, 3, 0, 0, 1, 0);
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

  printf("sub same\n");
  s21_initDecLMHScSign(&num1, 1, 0, 0, 0, 0);
  s21_initDecLMHScSign(&num2, 1, 0, 0, 0, 0);
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

  printf("sub small & big\n");
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

  printf("sub 0.15 - 0.3\n");
  s21_initDecLMHScSign(&num1, 15, 0, 0, 2, 0);
  s21_initDecLMHScSign(&num2, 3, 0, 0, 1, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_sub(num1, num2, &result);
  s21_printDecimal(result);

  printf("sub 0.5 - 0.32\n");
  s21_initDecLMHScSign(&num1, 5, 0, 0, 1, 0);
  s21_initDecLMHScSign(&num2, 32, 0, 0, 2, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_sub(num1, num2, &result);
  s21_printDecimal(result);

  printf("sub 10 - 15\n");
  s21_initDecLMHScSign(&num1, 10, 0, 0, 0, 0);
  s21_initDecLMHScSign(&num2, 15, 0, 0, 0, 0);
  s21_initDecLMHScSign(&result, 0, 0, 0, 0, 0);

  s21_printDecimal(num1);
  s21_printDecimal(num2);

  s21_sub(num1, num2, &result);
  s21_printDecimal(result);

#endif

  return 0;
}