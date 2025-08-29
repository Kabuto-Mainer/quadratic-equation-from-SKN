/*!
    \file
    \brief testing module
*/
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "is_near_zero.h"
#include "constats.h"
#include "test_fun.h"
#include "str_to_coef.h"
#include "solve_equation.h"
#include "input_man.h"

int test_for_solve_equation(struct coefficient_data* adr_coefficient_data,
                            struct about_roots_data* adr_root,
                            struct true_x_for_test* true_x) {

    FILE *test_sqrt = NULL;
    test_sqrt = fopen("test.txt", "r");
    double a_buf = NAN,
            b_buf = NAN,
            c_buf = NAN,
            x_1_buf = NAN,
            x_2_buf = NAN;

    if (!test_sqrt) {
        printf("ERROR with opening file\n");
        return -1;
    }
    for (int i = 0; i < HOW_MANY_TESTS; i++) {
        adr_root->x_1 = 0;
        adr_root->x_2 = 0;

        if (fscanf(test_sqrt,"%lf %lf %lf %lf %lf",
        &a_buf, &b_buf, &c_buf, &x_1_buf, &x_2_buf) != 5) {
            printf("ERROR\n");
            return 0;
        }
        adr_coefficient_data->a = (double) a_buf;
        adr_coefficient_data->b = (double) b_buf;
        adr_coefficient_data->c = (double) c_buf;
        true_x->x_1 = (double) x_1_buf;
        true_x->x_2 = (double) x_2_buf;

        solve_quadratic_equation(adr_coefficient_data, adr_root);

        if ( !(is_near_zero(adr_root->x_1 - true_x->x_1) && is_near_zero(adr_root->x_2 - true_x->x_2) )
        && !(is_near_zero(adr_root->x_1 - true_x->x_2) &&is_near_zero(adr_root->x_2 - true_x->x_1)) ) {

            printf("ERROR in solve_sqrt with %lf %lf %lf || must be %lf %lf || output %lf %lf\n",
            adr_coefficient_data->a, adr_coefficient_data->b, adr_coefficient_data->c,
            true_x->x_1, true_x->x_2, adr_root->x_1, adr_root->x_2);
        }
    }
    if (fclose(test_sqrt)) {
        printf("ERROR with closing test.txt");
        return 0;
    } //TODO: checker
    return 1;
}
//|| - попытка решения с динамической памятью - на доработке
//\/ --------------------------------------------------------
/*int test_for_sqrt(struct coefficient_data* adr_coefficient_data, struct about_roots_data* adr_root, struct true_x_for_test* true_x) {

    FILE *test_sqrt = NULL;
    test_sqrt = fopen("test.txt", "r");

    char* string = NULL;
    int file_sixe = 0;
    int add_index = 0;
    int buf_index = 0;
    double a_buf = NAN, b_buf = NAN, c_buf = NAN, x_1_buf = NAN, x_2_buf = NAN;

    if (!test_sqrt) {
        printf("ERROR with opening test.txt\n");
        return -1;
    }
    fseek(test_sqrt, 0, SEEK_END);
    file_size = ftello(test_sqrt);
    fclose(test_sqrt);

    string = (char*) malloc(file_size + 1);
    test_sqrt = fopen("test.txt", "r");

    for ((test_sqrt + add_index) < file_size) {
        string[add_index] = fgetc(test_sqrt);
        add_index++;
    }

        if (sscanf(test_sqrt + add_index,"%lf %lf %lf %lf %lf%n",
        &a_buf, &b_buf, &c_buf, &x_1_buf, &x_2_buf, &buf_index) != 5) {
            printf("ERROR\n");
            return 0;
        }
        adr_coefficient_data->a = (double) a_buf;
        adr_coefficient_data->b = (double) b_buf;
        adr_coefficient_data->c = (double) c_buf;
        true_x->x_1 = (double) x_1_buf;
        true_x->x_2 = (double) x_2_buf;
        printf("%lf %lf %lf %lf %lf\n", adr_coefficient_data->a, adr_coefficient_data->b, adr_coefficient_data->c, true_x->x_1, true_x->x_2);
        solve_sqrt(adr_coefficient_data, adr_root);

        if (!(is_near_zero(adr_root->x_1 - true_x->x_1) && is_near_zero(adr_root->x_2 - true_x->x_2)) &&
        !(is_near_zero(adr_root->x_1 - true_x->x_2) &&is_near_zero(adr_root->x_2 - true_x->x_1))) {
            printf("ERROR in solve_sqrt with %lf %lf %lf || must be %lf %lf || output %lf %lf\n",
            adr_coefficient_data->a, adr_coefficient_data->b, adr_coefficient_data->c, true_x->x_1, true_x->x_2, adr_root->x_1, adr_root->x_2);
        }
        add_index += buf_index;
    }
    fclose(test_sqrt); //TODO: checker
    return 0;
}*/
void test_is_char_x(void) {

    char test_mass[] = {'x', 'X', '2', '%', '@', '&'};
    int len_test = 6;
    int i = 0;
    for (i = 0; i < len_test - 4; i++) {
        if (!is_char_x(test_mass[i])) printf("ERROR in is_char_x with char %c\n", test_mass[i]);
    }
    for (i = 2; i < len_test; i++) {
        if (is_char_x(test_mass[i])) printf("ERROR in is_char_x with char %c\n", test_mass[i]);
    }
}
void test_power_of_x(void) {

    const int amount_of_tests = 6;

    char test_mass[amount_of_tests][5] = {"x^2", "x", "x^4", "23", "x^0", "x^3"};
    int answers_test[amount_of_tests] = {2, 1, 4, 0, 0, 3};

    for (int i = 0; i < amount_of_tests; i++) {

        if (power_of_x(&test_mass[i][0]) != answers_test[i]) {
            printf("ERROR in power_of_x with %s\n", test_mass[i]);
        }
    }
}
int test_str_to_coef(void) { //Пока не работает, выдает ошибку обращения

    struct coefficient_data coef_true = {NAN, NAN, NAN};
    struct coefficient_data output_coef = {NAN, NAN, NAN};
    char string[MAX_LEN] = "\0";
    char* adr_test = NULL;

    int file_size = 0;
    FILE *test_file = NULL;
    int add_index = 0;
    int buf_index = 0;
    if (!(test_file = fopen("test_str.txt", "r"))) {
        printf("ERROR in opening filetest_str.txt\n");
        return -1;
    }

    fseek(test_file, 0, SEEK_END);
    file_size = ftello(test_file); //TODO read about it
    fclose(test_file);

    test_file = fopen("test_str.txt", "r");
    adr_test = (char*) malloc(file_size + 1);
    fread(adr_test, sizeof(char),file_size, test_file);

    add_index = 0;
    while (add_index < file_size) {
        output_coef.a = 0;
        output_coef.b = 0;
        output_coef.c = 0;
        do_buffer_void(string);

        sscanf(adr_test + add_index, "%s %lf %lf %lf%n", string, &coef_true.a, &coef_true.b, &coef_true.c, &buf_index);
        printf("%s %lf %lf %lf %d\n", string, coef_true.a, coef_true.b, coef_true.b, buf_index);
        string_to_coefficient(string, &output_coef);

        if (!is_near_zero(coef_true.a - output_coef.a)
            || !is_near_zero(coef_true.b - output_coef.b)
            || !is_near_zero(coef_true.c - output_coef.c)) {

            printf("ERROR in test_str_to_coef with %s || must be %lf %lf %lf || output %lf %lf %lf\n",
            string, coef_true.a, coef_true.b, coef_true.c, output_coef.a, output_coef.b, output_coef.c);
        }
        add_index += buf_index;
    }
    return 0;
}
/*int test_str_to_coef() {

    struct coefficient_data coef_true = {NAN, NAN, NAN};
    struct coefficient_data output_coef = {NAN, NAN, NAN};

    char string[MAX_LEN] = "\0";

    FILE *test_file = NULL;
    if (!(test_file = fopen("test_str.txt", "r"))) {
        printf("ERROR with opening file in test_str_to_coef\n");
        return -1;
    }

    for (int i = 0; i < HOW_MANY_TESTS; i++) {

        output_coef.a = 0;
        output_coef.b = 0;
        output_coef.c = 0;

        do_buffer_void(string);
        fscanf(test_file, "%s %lf %lf %lf", string, &coef_true.a, &coef_true.b, &coef_true.c);
        string_to_coefficient(string, &output_coef);

        if (!is_near_zero(coef_true.a - output_coef.a)
            || !is_near_zero(coef_true.b - output_coef.b)
            || !is_near_zero(coef_true.c - output_coef.c)) {

            printf("ERROR in test_str_to_coef with %s || must be %lf %lf %lf || output %lf %lf %lf\n",
            string, coef_true.a, coef_true.b, coef_true.c, output_coef.a, output_coef.b, output_coef.c);
        }
    }
    return 0;
}*/
void test_plus_or_minus(void) {

    const int amount_of_tests = 5;

    char test_mass_1[amount_of_tests] = {'+', '-', '1', '@', '-'};
    int test_mass_2[amount_of_tests] = {2, 0, 0, 1, 3};
    int answers_test[amount_of_tests] = {1, 0, 1, -1, 0};

    for (int i = 0; i < amount_of_tests; i++) {

        if (plus_or_minus(test_mass_1[i], test_mass_2[i]) != answers_test[i]) {
            printf("ERROR in plus_or_minus with %c\n", test_mass_1[i]);
        }
    }
}
void test_str_to_int(void) {

    const int amount_of_tests = 5;

    char test_mass[amount_of_tests][MAX_DIGIT] = {"123", "", "94943", "234", "20"};
    int answers_test[amount_of_tests] = {123, 0, 94943, 234, 20};

    for (int i = 0; i < amount_of_tests; i++) {

        if (str_to_int(test_mass[i], (int) strlen(test_mass[i]))  != answers_test[i]) {
            printf("ERROR in str_to_int with %s\n", test_mass[i]);
        }
    }
}

void all_test_start() {

    struct coefficient_data test_coef = {.a = NAN, .b = NAN, .c = NAN};
    struct about_roots_data test_root = {.x_1 = 0, .x_2 = 0, .kol_roots = ZERO_ROOTS};
    struct true_x_for_test test_x = {.x_1 = 0, .x_2 = 0};

    test_str_to_coef();
    test_is_char_x();
    test_power_of_x();
    test_plus_or_minus();
    test_str_to_int();
    test_for_solve_equation(&test_coef, &test_root, &test_x);
}
