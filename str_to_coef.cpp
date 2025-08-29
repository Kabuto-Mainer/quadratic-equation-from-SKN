/*!
    \file
    \brief transformation module
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>

#include "is_near_zero.h"
#include "constats.h"
#include "str_to_coef.h"

int power_to_coef(struct str_to_coef_data* adr_stc_data,
                    struct coefficient_data* adr_coefficient_data) {

    assert(adr_coefficient_data);
    assert(adr_stc_data);

    switch (adr_stc_data->power) {

        case -2:
            printf("\033[1;34mNot correct input\n\033[1;0m");
            return -1;

        case -1:
            return -1;

        case 0:
            if (is_near_zero(adr_stc_data->buffer)) {
                adr_stc_data->buffer++;
            }
            adr_coefficient_data->c += adr_stc_data->buffer;
            return 0;

        case 1:
            if (is_near_zero(adr_stc_data->buffer)) {
                adr_coefficient_data->b += 1;
            }
            adr_coefficient_data->b += adr_stc_data->buffer;
            return 0;

        case 2:
            if (is_near_zero(adr_stc_data->buffer)) {
                adr_coefficient_data->a += 1;
            }
            adr_coefficient_data->a += adr_stc_data->buffer;
            adr_stc_data->index += 2;
            return 0;

        default:
            printf("\033[1;34mEquation with power more, than 2 we do not decide\n\033[1;0m");
            return -1;
    }
}
int power_of_x(char* string) {

    assert(string);

    int len_power = 0;
    double power = 0;

    if (!is_char_x(*string)) {
        return 0;
    }
    switch (is_struct_equation_good(*(string + 1))) {

        case 2:
            power = str_to_double(string + 2, &len_power);

            if (!is_near_zero(int(power) - power)) {
                printf("\033[1;34mWe do not decide equation with float power\n\033[1;0m");
                return -1;
            }
            power = int(power);

            if (power < MAX_POWER) {
                return power; // Higher is casting to int and checking, what power is natural
            }
            printf("\033[1;34mWe do not decide equation with power more %d\n\033[1;m", MAX_POWER);
            return -1;

        case 1:
            return 1;

        case 0:
            return -1;
        default:
            printf("\033[1;31mERROR in power_of_x (default)\n\033[1;0m");
            return NAN;
    }
    printf("\033[1;31mERROR in power_of_x\n\033[1;0m");
    return NAN;
}
int plus_or_minus(int symbol, int add_index) {
    // printf("Plus or Minus: %c\n", symbol); For repair
    if (add_index == 0 && symbol != '-') {
        return 1;
    }

    else {
        switch (symbol) {

            case '+':
                return 1;

            case '-':
                return 0;

            default:
                return -1;
        }
    }
    return -1;
}
int is_char_x(int symbol) {

    if (toupper(symbol) == 'X') {
        return 1;
    }
    return 0;
}
int string_to_coefficient(char* string, struct coefficient_data* adr_coefficient_data) {

    assert(strlen(string) != 0);
    assert(adr_coefficient_data);
    assert(!isnan(adr_coefficient_data->a));
    assert(!isnan(adr_coefficient_data->b));
    assert(!isnan(adr_coefficient_data->c));

    struct str_to_coef_data all = {.power = 0,
                                    .buffer = 0,
                                    .index = 0,
                                    .is_plus = true};
    char* end; //TODO как инициализировать
    int len_number = 0;

    while (string[all.index] != '\0') {

        all.power = 0;
        all.is_plus = plus_or_minus(string[all.index], all.index);

        if (all.is_plus == -1) {
            printf("\033[1;34mInput is not correct\n\033[1;34m");
            return -1;
        }

        all.buffer = strtod(string + all.index, &end);
        // printf("Buffer: %lg\n", all.buffer); For repair
        len_number = len_num(string + all.index, end);

        if ( !(all.index == 0 && string[0] != '-' && all.buffer == 0) ) {
        // ^^^^^ This comparision is required, because if coefficient can be zero
            all.index += len_number;
        }

        if (all.buffer != 0 && is_near_zero(all.buffer)) {
        // ^^^^^ This comparision is required, because if coefficient can be zero
            printf("\033[1;34mSorry, but we do not support such precision in solving the equation. Please, use less precise coefficient\n\033[1;0m");
            return -1;
        }

        if ((all.buffer > MAX_NUM) || (all.buffer < MIN_NUM)) {
            printf("\033[1;34mThese coefficient is too big ot small. Please use another coefficient\n\033[1;0m");
            return -1;
        }

        all.power = power_of_x(&string[all.index]);
        // printf("Power: %d\n", all.power); For repair
        if (power_to_coef(&all, adr_coefficient_data)) {
            return -1;
        }

        all.index++;
    }
    return 0;
}
long int str_to_int(char* string, int len_num) {

    assert(string);

    char alpha[] = {"0123456789"};
    long int result = 0;

    for (int i = 0; i < len_num; i ++) {
        for (int cof = 0; cof < 10; cof++) {

            if (string[i] == alpha[cof]) {
            // It is always int num here
                result += cof * ((int) pow(10, len_num - i - 1));
            }
        }
    }
    return result;
}
long int checker_int_number(char* string, int* len_num) {

    assert(len_num);
    assert(string);

    char buffer[MAX_DIGIT] = "";
    bool is_in_digit = true;
    int add_index = 0;

    while (is_in_digit) {
        if (isdigit(*(string + add_index))) {

            buffer[add_index] = *(string + add_index);
            add_index++;
        }
        else is_in_digit = false;
    }
    if (add_index == 0) {
        return 0;
    }
    *len_num = add_index;

    return str_to_int(buffer, add_index);
}
double str_to_double(char* string, int* return_len) {

    assert(string);
    assert(return_len);

    long int full_part = 0;
    long int frac_part = 0;

    int len_num = 0;
    int buffer = 0;

    bool is_float = false;

    full_part = checker_int_number(string, &buffer);
    len_num += buffer;

    if (*(string + len_num) == '.' || *(string + len_num) == ',') {
        is_float = true;
    }
    if (is_float) {
        len_num++;
        frac_part = checker_int_number(string + len_num, &buffer);
        len_num += buffer;
    }
    *return_len = len_num;

    return ((double) full_part) +  ((double) frac_part) / pow(10, buffer);
}
int len_num(char* string, char* end) {

    int i = 0;

    while (*(string + i) != *end) {
        i++;
    }
    if (i == 0) {
        return 1;
    }
    return i;
}
int is_struct_equation_good(int symbol) {

    if (symbol == '^') {
        return 2;
    }
    if  (symbol == '+' || symbol == '-' || symbol == '\0') {
        return 1;
    }
    return 0;
}
