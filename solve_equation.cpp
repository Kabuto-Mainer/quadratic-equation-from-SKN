/*!
    \file
    \brief solving module
*/
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "solve_equation.h"
#include "is_near_zero.h"
#include "constats.h"

void checking_type_equation(struct coefficient_data* adr_coefficient_data,
                            struct about_roots_data* adr_roots_and_amount) {

    assert(adr_coefficient_data);
    assert(!isnan(adr_coefficient_data->a));
    assert(!isnan(adr_coefficient_data->b));
    assert(!isnan(adr_coefficient_data->c));
    assert(adr_roots_and_amount);

    adr_roots_and_amount->x_1 = 0;
    adr_roots_and_amount->x_2 = 0;

    if (is_near_zero(adr_coefficient_data->a)) {

        if (is_near_zero(adr_coefficient_data->b)) {

            if (is_near_zero(adr_coefficient_data->c)) {
                adr_roots_and_amount->kol_roots = INF_ROOTS;
            }
            else {
                adr_roots_and_amount->kol_roots = ERROR_ROOTS;
            }
        }
        else {
            solve_linear_equation(adr_coefficient_data, adr_roots_and_amount);
        }
    }
    else {
        solve_quadratic_equation(adr_coefficient_data, adr_roots_and_amount);
    }
}
void solve_linear_equation(struct coefficient_data* adr_coefficient_data,
                            struct about_roots_data* adr_roots_and_amount) {

    assert(adr_coefficient_data);
    assert(adr_roots_and_amount);

    adr_roots_and_amount->x_1 = -1 * adr_coefficient_data->c / adr_coefficient_data->b;

    if (is_near_zero(adr_roots_and_amount->x_1)){
        adr_roots_and_amount->x_1 *= -1;
    }
    adr_roots_and_amount->kol_roots = ONE_ROOT;
}
int solve_quadratic_equation(struct coefficient_data* adr_coefficient_data,
                            struct about_roots_data* adr_roots_and_amount) {

    assert(adr_coefficient_data);
    assert(adr_roots_and_amount);

    if (adr_coefficient_data->b > MAX_NUM || adr_coefficient_data->b < MIN_NUM ||
        adr_coefficient_data->a > MAX_NUM || adr_coefficient_data->a < MIN_NUM ||
        adr_coefficient_data->c > MAX_NUM || adr_coefficient_data->c < MIN_NUM) {

        printf("\033[1;34mSorry, but we do not support so big or small digit, please, enter another equation\n\033[1;0m");
        return -1;
    }

    double Discriminant = adr_coefficient_data->b*adr_coefficient_data->b
    - 4*adr_coefficient_data->a*adr_coefficient_data->c;

    if (Discriminant < 0 && !is_near_zero(Discriminant)) {

        adr_roots_and_amount->kol_roots = ZERO_ROOTS;
        return -1;
    }
    else {

        Discriminant = abs(Discriminant);
    }
    if (is_near_zero(Discriminant)) {

        adr_roots_and_amount->kol_roots = ONE_ROOT;
        adr_roots_and_amount->x_1 = -1 * adr_coefficient_data->b / (2 * adr_coefficient_data->a);
        adr_roots_and_amount->x_2 = adr_roots_and_amount->x_1;
    }
    else {

        adr_roots_and_amount->kol_roots = TWO_ROOTS;
        adr_roots_and_amount->x_1 = (-1 * adr_coefficient_data->b + sqrt(Discriminant))
                        / (2 * adr_coefficient_data->a);
        adr_roots_and_amount->x_2 = (-1 * adr_coefficient_data->b - sqrt(Discriminant))
                        / (2 * adr_coefficient_data->a);
    }
    return 0;
}
