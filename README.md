# Decimal-
## Chapter II

## Information

The Decimal value type represents decimal numbers from positive 79,228,162,514,264,337,593,543,950,335 to negative 79,228,162,514,264,337,593,543,950,335. The default value of a Decimal is 0. The Decimal value type is suitable for financial calculations that require a large number of significant integral and fractional digits and that do not have rounding errors. The Decimal type does not eliminate the need for rounding. Rather, it minimizes rounding errors.

When the result of the division and multiplication is passed to the Round method, the result suffers no loss of precision.

A Decimal number is a floating point value that consists of a sign, a numerical value where each digit in the value ranges from 0 to 9, and a scaling factor that indicates the position of a floating decimal point that separates the integral and fractional parts of the numerical value.

The binary representation of a Decimal value consists of a 1-bit sign, a 96-bit integer, and a scaling factor that is used to divide the 96-bit integer and specify what portion of it is a Decimal fraction. The scaling factor is implicitly the number 10 raised to an exponent between 0 and 28. Therefore, the binary representation of a Decimal value has the form ((-2^96 to 2^96) / 10^(0 to 28)), where -(2^96-1) is equal to MinValue and 2^96-1 is equal to MaxValue.

The scaling factor can also preserve any trailing zeros in a Decimal number. Trailing zeros do not affect the value of a Decimal number in arithmetic or comparison operations. 

### Binary representation

The binary representation of a Decimal number consists of a 1-bit sign, a 96-bit integer number, and a scaling factor that is used to divide the integer number and specify what portion of it is a decimal fraction. The scaling factor is implicitly the number 10 raised to an exponent between 0 and 28.

The Decimal number can be implemented as a four-element array of 32-bit signed integers (`int bits[4];`).

`bits[0]`, `bits[1]`, and `bits[2]` contain the low, middle, and high 32 bits of the 96-bit integer, respectively.

`bits[3]` contains the scaling factor and sign and consists of the following parts:
- Bits 0 through 15, the lower word, are unused and must be zero.
- Bits 16 to 23 must contain an exponent between 0 and 28, indicating the power of 10 to divide the integer.
- Bits 24 through 30 are unused and must be zero.
- Bit 31 contains the sign; 0 is positive and 1 is negative.

Note that the bit representation distinguishes between negative and positive zeros. These values can be treated as equal in all operations.

### Example:

```c
typedef struct 
{
    int bits[4];
} s21_decimal;
```

### Arithmetic Operators

| Operator name | Operators  | Function                                                                           | 
| ------ | ------ |------------------------------------------------------------------------------------|
| Addition | + | int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)         |
| Subtraction | - | int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) |
| Multiplication | * | int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) | 
| Division | / | int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) |

The functions return the error code:
- 0 — OK;
- 1 — the number is too large or equal to infinity;
- 2 — the number is too small or equal to negative infinity;
- 3 — division by 0.

*Note on the numbers that do not fit into the mantissa:*
- *When getting numbers that do not fit into the mantissa during arithmetic operations, use bank rounding (for example, 79,228,162,514,264,337,593,543,950,335 — 0.6 = 79,228,162,514,264,337,593,543,950,334)*

### Comparison Operators

| Operator name | Operators  | Function | 
| ------ | ------ | ------ |
| Less than | < | int s21_is_less(s21_decimal, s21_decimal) |
| Less than or equal to | <= | int s21_is_less_or_equal(s21_decimal, s21_decimal) | 
| Greater than | > |  int s21_is_greater(s21_decimal, s21_decimal) |
| Greater than or equal to | >= | int s21_is_greater_or_equal(s21_decimal, s21_decimal) | 
| Equal to | == |  int s21_is_equal(s21_decimal, s21_decimal) |
| Not equal to | != |  int s21_is_not_equal(s21_decimal, s21_decimal) |

Return value:
- 0 — FALSE;
- 1 — TRUE.

### Convertors and parsers

| Convertor/parser | Function | 
| ------ | ------ |
| From int  | int s21_from_int_to_decimal(int src, s21_decimal *dst) |
| From float  | int s21_from_float_to_decimal(float src, s21_decimal *dst) |
| To int  | int s21_from_decimal_to_int(s21_decimal src, int *dst) |
| To float  | int s21_from_decimal_to_float(s21_decimal src, float *dst) |

Return value — code error:
- 0 — OK;
- 1 — convertation error.

*Note on the conversion of a float type number:*
- *If the numbers are too small (0 < |x| < 1e-28), return an error and value equal to 0*.
- *If the numbers are too large (|x| > 79,228,162,514,264,337,593,543,950,335) or are equal to infinity, return an error*.
- *When processing a number with the float type, convert all the significant decimal digits contained in it. If there are more than 7 such digits, the number is rounded to the closest one that does not have more than 7 significant decimal digits.*

*Note on the conversion from decimal type to int:*
- *If there is a fractional part in a decimal number, it should be discarded (for example, 0.9 is converted to 0)*.


### Other functions

| Description | Function                                                         | 
| ------ |------------------------------------------------------------------|
| Rounds a specified Decimal number to the closest integer toward negative infinity. | int s21_floor(s21_decimal value, s21_decimal *result)            |	
| Rounds a decimal value to the nearest integer. | int s21_round(s21_decimal value, s21_decimal *result)    |
| Returns the integral digits of the specified Decimal; any fractional digits are discarded, including trailing zeroes. | int s21_truncate(s21_decimal value, s21_decimal *result) |
| Returns the result of multiplying the specified Decimal value by negative one. | int s21_negate(s21_decimal value, s21_decimal *result)   |

Return value — code error:
- 0 — OK;
- 1 — calculation error.

## Chapter III

## Part 1. Implementation of the decimal.h library functions

The functions of the decimal.h library described [above](#information) must be implemented:
- The library must be developed in C language of C11 standard using gcc compiler.
- The library code must be located in the src folder on the develop branch.
- Do not use outdated and legacy language constructions and library functions. Pay attention to the legacy and obsolete marks in the official documentation on the language and the libraries used. Use the POSIX.1-2017 standard.
- When writing code it is necessary to follow the Google style.
- Make it as a static library named *s21_decimal* (with the s21_decimal.h header file).
- The library must be developed according to the principles of structured programming.
- Use prefix s21_ before each function.
- Prepare full coverage of library functions code with unit-tests using the Check library.
- Unit tests must cover at least 80% of each function (checked using gcov).
- Provide a Makefile for building the library and tests (with targets all, clean, test, s21_decimal.a, gcov_report).
- The gcov_report target should generate a gcov report in the form of an html page. Unit tests must be run with gcov flags to do this.
- When implementing decimal, stick to [the binary representation](#binary-representation) with the integer `bits` array as specified in the [example above](#example). Observe the position of the digits of a number in the `bits` array;
- It is forbidden to use the __int128 type.
- Trailing zeros can be as preserved as deleted (except for the `s21_truncate` function).
- The defined type must support numbers from -79,228,162,514,264,337,593,543,950,335 to +79,228,162,514,264,337,593,543,950,335.
