#ifndef IS_NEAR_ZERO_H
#define IS_NEAR_ZERO_H
/*!
    \file
    \brief is_near_zero
*/

/**
 * @brief check, is number near zero
 *
 * @param [in] num input number
 * @return int 1 if true, else 0
 */
int is_near_zero(double num);

const double PRECISION = 1e-20;///< Max precision, which program support

#endif // IS_NEAR_ZERO_H
