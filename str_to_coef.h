/*!
    \file
    \brief transformation module lib
*/
#ifndef STR_TO_COEF_H
#define STR_TO_COEF_H
/**
 * @brief transformation two int number to double
 *
 * @param [in] string string with number
 * @param [in] return_len addres, where function write len of number
 * @return double number
 */
double str_to_double(char* string, int* return_len);
/**
 * @brief create string for str_to_int and return number
 *
 * @param [in] string input string
 * @param [in] len_num address, where fuction write len of number
 * @return long int number
 */
long int checker_int_number(char* string, int* len_num);
/**
 * @brief transform string to int number
 *
 * @param string create string for str_to_int
 * @param len_num address, where function write len of number
 * @return long int number
 */
long int str_to_int(char* string, int len_num);
/**
 * @brief transform string to cofficient
 *
 * @param [in] string input string
 * @param [in] adr_coefficient_data struct with coefficient
 * @return int -1 if ERROR in input, else 0
 */
int string_to_coefficient(char* string, struct coefficient_data* adr_coefficient_data);
/**
 * @brief distribution number depending on power of x
 *
 * @param [in] adr_stc_data struct with power
 * @param [in] adr_coefficient_data struct with coefficients
 * @return int 0 if all OK, else -1
 */
int power_to_coef(struct str_to_coef_data* adr_stc_data,
                    struct coefficient_data* adr_coefficient_data);
/**
 * @brief check, is symbol x or not
 *
 * @param [in] symbol input symbol
 * @return int 1 if true, else 0
 */
int is_char_x(int symbol);
/**
 * @brief is symbol + or - or another char
 *
 * @param [in] symbol input char
 * @param [in] add_index index of symbol // For time, when coefficient a = 1(x^2-4x+5)
 * @return int 1 if +, 0 if -, else 0
 */
int plus_or_minus(int symbol, int add_index);
/**
 * @brief find power of x
 *
 * @param [in] string input string
 * @return int power of x if all OK, else -1
 */
int power_of_x(char* string);
/**
 * @brief find length digit string
 *
 * @param [in] string input string
 * @param [in] end symbol fo end
 * @return int len digit string
 */
int len_num(char* string, char* end);
/**
 * @brief checking, is struct of equation is true
 *
 * @param [in] symbol symbol after x
 * @return int 2 if it is ^, 1 if +,-,\0 , else 0
 */
int is_struct_equation_good(int symbol);
#endif // STR_TO_COEF_H
