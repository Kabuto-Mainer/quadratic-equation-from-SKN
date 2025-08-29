#ifndef CONSTATS_H
#define CONSTATS_H
/*!
    \file
    \brief library with consts and structs
*/
#include <math.h>
const int MAX_USERS_ERRORS = 20; ///< How many error can do user. If he do more error - exit program
const int MAX_DIGIT = 400; ///< Max length of coefficient
const int MAX_LEN = 1000; ///< Max length of equation
const int MAX_POWER = 5; ///< Max power what program can scan
 /**
  * \enum AMOUNT_OF_ROOTS
  * \brief how many roots in sqrt equation
  */
enum AMOUNT_OF_ROOTS {
    ONE_ROOT = 1, /**< if there is only one root */
    TWO_ROOTS = 2, /**< if there is two valid roots */
    ZERO_ROOTS = 0, /**< if there is zero valid roots */
    INF_ROOTS = 10, /**< if coefficients are zero and there is infinity  */
    ERROR_ROOTS = -1 /**< if coefficients A and B are zero but coefficient C is not zero */
};
const double MAX_NUM = 1e20;///< Max num, which user can enter
const double MIN_NUM = -1e20;///< Min num, which user can enter
/**
 * \struct coefficient_data
 * \brief struct with coefficient of quadrat equation
 */
struct coefficient_data {
    double a; /**< coefficient A*/
    double b; /**< coefficient B*/
    double c; /**< coefficient C*/
}; //TODO coefficient_data
/**
 * \struct about_roots_data
 * \brief struct with roots of quadrat equation and quantity of roots
 */
struct about_roots_data{
    double x_1; /**< Root_of_equation*/
    double x_2; /**< Root_of_equation*/
    AMOUNT_OF_ROOTS kol_roots;/**< Quantity of roots */
}; //TODO rename
/**
 * \struct str_to_coef_data
 * \brief struct with arguments of string_to_coefficient
 */
struct str_to_coef_data {
    int power; /**< Power of x */
    double buffer; /**< Buffer, where program write scan number */
    int index; /**< Index of considered element */
    int len; /**< Length of scan number */
    int is_plus; /**< Sign of number */
};
#endif // CONSTATS_H
