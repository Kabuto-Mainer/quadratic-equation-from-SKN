//#include <TXLib.h>
/*!
    \file
    \brief main module
*/
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include <cstring>
#include <assert.h>
#include <windows.h>

#include "constats.h"
#include "str_to_coef.h"
#include "solve_equation.h"
#include "test_fun.h"
#include "input_man.h"
#include "secret_cods.h"
#include "print_all.h"

/**
 * @brief Main Function
 *
 * @param [in] argc amount of terminal arguments
 * @param [in] argv massive with arguments
 * @return int 0
 */
int main(int argc, char* argv[])
{
    printf("\033[1;31mMAU\n\033[1;0m");

    char mass[MAX_LEN] = "";
    struct coefficient_data main_struct_coef = {.a = NAN, .b = NAN, .c = NAN}; //TODO rename
    struct about_roots_data main_roots = { .x_1 = NAN, .x_2 = NAN, .kol_roots = ZERO_ROOTS};
    struct secret_code_for_terminal arguments = {.is_without_tests = false,
                                                .is_master_input = false,
                                                .poltorashka = false,
                                                .is_standard_work = true};

    bool is_correct_input = true;
    comand_str_arguments(argc, argv, &arguments);
    if (arguments.poltorashka) {
        draw_cat();
    }
    if (!arguments.is_without_tests) {
        all_test_start();
    }
    if (arguments.is_standard_work)
        printf("\033[1;34mThis program solves a quadratic equation in valid\n\033[1;0m");

    while (true && arguments.is_standard_work) {
        main_struct_coef.a = 0; // 0 is must be here
        main_struct_coef.b = 0;
        main_struct_coef.c = 0;
        if (arguments.is_master_input) {
            master_input_coefficient(&main_struct_coef);
        }
        else {
            printf("\033[1;34mType you equation (for example x^2 - 16x + 498)\n\033[1;0m");
            do_buffer_void(mass);
            input_data_for_base_mod(mass, &is_correct_input);
            if (!is_correct_input) break;
            if (string_to_coefficient(mass, &main_struct_coef)) {
                printf("\033[1;34mType correct equation\n\033[1;0m");
                continue;
            }
        }
        // printf("%g %g %g\n", main_struct_coef.a,main_struct_coef.b, main_struct_coef.c); for repair
        checking_type_equation(&main_struct_coef, &main_roots);
        print_results(&main_roots);
        printf("\033[1;36mFor continue type @\n\033[1;0m");

        if (is_must_continue())
            continue;
        else
            break;
    }
    printf("\033[1;32mCOMMIT GITHAB\n\033[1;0m");
    return 0;
}
