
#include <stdio.h>
#include <assert.h>
#include "constats.h"
#include "print_all.h"

int print_results(struct about_roots_data* adr_roots_and_amount) {

    assert(adr_roots_and_amount);

    switch (adr_roots_and_amount->kol_roots) {

        case ERROR_ROOTS:
            printf("Impossible equation\n");
            break;

        case ZERO_ROOTS:
            printf("Equation has not valid solution\n");
            break;

        case ONE_ROOT:
            printf("Equation has one valid solution: %lf\n", adr_roots_and_amount->x_1);
            break;

        case TWO_ROOTS:
            printf("Equation has two valid solution: %lf and %lf\n", adr_roots_and_amount->x_1,
                                                                    adr_roots_and_amount->x_2);
            break;

        case INF_ROOTS:
            printf("INFINITI is not the limit\n");
            break;

        default:
            printf("ERROR in function print_results - default\n");
            return 0;
    }
    return 1;
}
void draw_cat(void) {
    printf("  /\\_/\\\n");
    printf(" ( o.o )\n");
    printf("  > ^ <\n");
}
