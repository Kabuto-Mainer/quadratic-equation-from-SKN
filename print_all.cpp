
#include <stdio.h>
#include <assert.h>
#include <windows.h>
#include "constats.h"
#include "print_all.h"

int print_results(struct about_roots_data* adr_roots_and_amount) {

    assert(adr_roots_and_amount);

    switch (adr_roots_and_amount->kol_roots) {

        case ERROR_ROOTS:
            printf("\033[1;32mImpossible equation\n\033[1;0m");
            break;

        case ZERO_ROOTS:
            printf("\033[1;32mEquation has not valid solution\n\033[1;0m");
            break;

        case ONE_ROOT:
            printf("\033[1;32mEquation has one valid solution: %lf\n\033[1;0m", adr_roots_and_amount->x_1);
            break;

        case TWO_ROOTS:
            printf("\033[1;32mEquation has two valid solution: %lf and %lf\n\033[1;0m", adr_roots_and_amount->x_1,
                                                                    adr_roots_and_amount->x_2);
            break;

        case INF_ROOTS:
            printf("\033[1;32mINFINITI is not the limit\n\033[1;0m");
            break;

        default:
            printf("\033[1;31mERROR in function print_results - default\033[1;0m\n");
            return 0;
    }
    return 1;
}
void draw_cat(void) {
    printf("\033[1;35m  /\\_/\\\033[1;0m\n");
    printf("\033[1;35m ( o.o )\033[1;0m\n");
    printf("\033[1;35m  > ^ <\033[1;0m\n");
}
// void set_red_to_green()
// void set_green_to_red()
