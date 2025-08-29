/*!
    \file
    \brief inputing module
*/
#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include "input_man.h"
#include "constats.h"

void coefficient_input_for_master_mod(double* coefficient, char alpha) {

    assert(coefficient);

    char buffer[MAX_LEN] = "\0";
    char* end; //TODO надо инициализировать, но не знаю чем(

    printf("Input coefficient %c: ", alpha);
    scanf("%s", buffer);

    while (!isdigit(*buffer)) {

        printf("\n%s is not a digit\n", buffer);
        printf("Input coefficient %c: ", alpha);
        scanf("%s", buffer);

        while (getchar() != '\n') continue;
    }
    *coefficient = strtod(buffer, &end);
}
void do_buffer_void(char* string) {
    assert(string);
    for (int i = 0; i < MAX_LEN; i++) {
        *(string + i) = '\0';\
    }
}
int input_data_for_base_mod(char* string_data, bool* is_user_error) {

    assert(string_data);
    assert(is_user_error);

    for (int counter_error = 0; counter_error < MAX_USERS_ERRORS; counter_error++) {
        if (counter_error == 19) {

            puts("You have exhausted my patience. I'm shutting down");
            *is_user_error = false;
            return 0;
        }

        bool is_char_correct = true;
        int len_equation = 0;
        int symbol = '\0';

        while ((symbol = getchar()) != '\n') {
            if (symbol != ' ') {

                if (is_correct_input(symbol)) {
                    string_data[len_equation] = (char) symbol;
                    len_equation++;
                }
                else if (len_equation == 0 && symbol == '\n') {
                    continue;
                }

                else {
                    while (getchar() != '\n') {
                        continue;
                    }
                    printf("Please, do not type another symbol without digit, \"x\", \"^\", \"+\", \"-\", \".\", \",\"\n");

                    is_char_correct = false;
                    break;
                }
            }
        }
        if (is_char_correct) {
            if (len_equation) {
                return 1;
            }
            else {
                printf("Please, retype your equation\n");
                continue;
            }
        }
    }
    return 0;
}
int is_correct_input(int symbol) {

    if (isdigit((char) symbol) || symbol == 'x' || symbol == 'X' || symbol == '^'
    || symbol == '+' || symbol == '-' || symbol == ',' || symbol == '.') {
        return 1;
    }
    else {
        return 0;
    }
}
int is_must_continue() {

    if (getchar() == '@') {
        while (getchar() != '\n') continue;
        return 1;
    }
    else {
        puts("Good Bye\n");
        return 0;
    }
}
void master_input_coefficient(struct coefficient_data* adr_coefficient_data) {

    assert(adr_coefficient_data);

    coefficient_input_for_master_mod(&adr_coefficient_data->a, 'A');
    coefficient_input_for_master_mod(&adr_coefficient_data->b, 'B');
    coefficient_input_for_master_mod(&adr_coefficient_data->c, 'C');
}
