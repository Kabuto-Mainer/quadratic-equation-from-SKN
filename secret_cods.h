/*!
    \file
    \brief secret lib
*/
#ifndef SECRET_CODS_H
#define SECRET_CODS_H
/**
 * @struct secret_code_for_terminal
 * @brief struct with flag for secret cods
 *
 */
 #include "constats.h"
struct secret_code_for_terminal {
    bool is_without_tests; /**< Is program must start with test */
    bool is_master_input; /**< Is program must use standard input or use master input */
    bool poltorashka; /**< Meow */
    bool is_standard_work; /**< Is program must work is base mod */
};
const char is_test[MAX_DIGIT] = "wtests"; /**< Secret code (is_without_tests */
const char SKN[MAX_DIGIT] = "godmod"; /**< Secret code (is_master_input)*/
const char Cats[MAX_DIGIT] = "meow"; /**< Secret code (meow) */
const char test[MAX_DIGIT] = "test"; /**< Secret code (is_standard_work) */

/**
 * @brief work with arguments of terminal
 *
 * @param amount_arguments amount of arguments
 * @param mass_with_arguments massive with arguments
 * @param code_data struct with secret cods
 */
void comand_str_arguments(int amount_arguments, char* mass_with_arguments[],
                            struct secret_code_for_terminal* code_data);

#endif // SECRET_CODS_H
