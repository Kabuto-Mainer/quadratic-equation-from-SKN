/*!
    \file
    \brief solving module lib
*/
#ifndef SOLVE_EQUATION_H
#define SOLVE_EQUATION_H
/*!
 * @brief checking type of equation and call necessary function for solve equation
 *
 * @param [in] adr_coefficient_data struct with coefficients
 * @param [in] adr_roots_and_amount struct with roots
 */
void checking_type_equation(struct coefficient_data* adr_coefficient_data,
                            struct about_roots_data* adr_roots_and_amount);
/**
 * @brief solve linear equation with coefficient A = 0
 *
 * @param [in] adr_coefficient_data struct with coefficients
 * @param [in] adr_roots_and_amount struct with roots
 */
void solve_linear_equation(struct coefficient_data* adr_coefficient_data,
                            struct about_roots_data* adr_roots_and_amount);
/**
 * @brief solve quadratic equation with coefficient A != 0
 *
 * @param [in] adr_coefficient_data struct with coefficients
 * @param [in] adr_roots_and_amount struct with roots
 * @return int -1 if D < 0, else 0
 */
int solve_quadratic_equation(struct coefficient_data* adr_coefficient_data,
                            struct about_roots_data* adr_roots_and_amount);
#endif // SOLVE_EQUATION_H
