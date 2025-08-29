/*!
    \file
    \brief testing module lib
*/
#ifndef TEST_FUN_H
#define TEST_FUN_H
/**
 * @struct true_x_for_test
 * @brief struct with true roots for testing function
 */
struct true_x_for_test {
    double x_1; /**< First root */
    double x_2; /**< Second root */
};
/**
 * @brief Tests string_to_coefficient
 *
 * @return int 0, if all is OK, else -1
 */
int test_str_to_coef();
/**
 * @brief test is_char_xc
 *
 */
void test_is_char_x(void);
/**
 * @brief test power_of_x
 *
 */
void test_power_of_x(void);
/**
 * @brief test plus_or_minus
 */
void test_plus_or_minus(void);
/**
 * @brief test str_to_int
 */
void test_str_to_int(void);
/**
 * @brief test solve_sqrt
 *
 * @param [in] adr_coefficient_data struct with coefficient
 * @param [in] adr_root struct where function save roots
 * @param [in] true_x struct with true roots
 * @return int 1, if all OK, else 0
 */
int test_for_solve_equation(struct coefficient_data* adr_coefficient_data,
                    struct about_roots_data* adr_root,
                    struct true_x_for_test* true_x);
/**
 * @brief start all test in program
 *
 */
void all_test_start();
/*struct str_and_coef_for_test{
    char string[MAX_LEN];
    struct coefficient coef;
}*/
const int MAX_TESTS = 99972; ///< Max amount of tests || It never must change
const int HOW_MANY_TESTS = 10; ///< How many tests do testing function
#endif // TEST_FUN_H
