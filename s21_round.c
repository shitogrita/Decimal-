#include "main.h"


void s21_copy(s21_decimal value, s21_decimal *result) {
    for (int i = 0; i < 4; i ++) {
        result->bits[i] = value.bits[i];
    }
}

void s21_truncate(s21_decimal value, s21_decimal *result) {
    s21_copy(value, result);
    //result->bits[0] &= 0xFFFFFFFF;
    result->bits[1] = 0;           
    result->bits[2] = 0;
}

void s21_setScale(s21_decimal *value, int scale) {
    value->bits[3] &= ~(0xFF << 16); 
    value->bits[3] |= (scale << 16); 
}


int s21_round(s21_decimal value, s21_decimal *result) {
    int retVal = OK;
    int scale = s21_getScale(value);
    //s21_decimal abs_value = s21_absDecimal(value);
    int sign = s21_getSign(value);
    s21_decimal temp_value = value;

    if (scale > 0) {
        s21_decimal integerPart;
        s21_copy(temp_value, &integerPart);
        s21_setScale(&integerPart, 0); 

        s21_decimal fractionalPart;
        s21_copy(temp_value, &fractionalPart);
        for (int i = 0; i < scale; i++) {
            fractionalPart.bits[0] %= 10; 
        }
        if (fractionalPart.bits[0] >= 5) {
            integerPart.bits[0] += 1; 
        }

        result->bits[0] = integerPart.bits[0];
        result->bits[1] = integerPart.bits[1];
        result->bits[2] = integerPart.bits[2];
        result->bits[3] = integerPart.bits[3];

    } else {
        s21_copy(temp_value, result);
    }
    
    s21_fillScaleSign(result, 0, sign);
    //s21_setScale(result, 0);
    
    if (sign) {
        //s21_setSign(result, sign);
        s21_fillScaleSign(result, scale, sign);

    }

    return retVal; 
}