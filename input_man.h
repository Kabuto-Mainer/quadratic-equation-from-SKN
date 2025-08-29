/*!
    \file
    \brief inputing module lib
*/
#ifndef INPUT_MAN_H
#define INPUT_MAN_H
/**
 * @brief checking, must program continue
 *
 * @return int 1 if true, else 0
 */
int is_must_continue(void);
/**
 * @brief check input symbols analyze they for correct input
 *
 * @param [in] string_data input string
 * @param [in] is_user_error address bool variable
 * @return int 1 if all Ok, else 0
 */
int input_data_for_base_mod(char* string_data, bool* is_user_error);
/**
 * @brief checking, is input symbols is correct
 *
 * @param [in] symbol input symbol
 * @return int 1 if all OK, else 0
 */
int is_correct_input(int symbol);
/**
 * @brief clean string
 *
 * @param [in] string input string
 */
void do_buffer_void(char* string);
/**
 * @brief input in God Mod
 *
 * @param [in] adr_coefficient_data struct with coefficients
 */
void master_input_coefficient(struct coefficient_data* adr_coefficient_data);
/**
 * @brief extra program to process input data
 *
 * @param [in] coefficient input data
 * @param [in] alpha name of coefficient
 */
void coefficient_input_for_master_mod(double* coefficient, char alpha);
#endif // INPUT_MAN_H
