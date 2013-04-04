#ifndef _LIB1_H_
#define _LIB1_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input_valid_string_data(char *information, char *input_text, int max_number_of_symbols);
int input_valid_int_data(char *information, int Min, int Max);
int auxiliary_information_for_user(int argc, char **argv);

#endif /* _LIB1_H_ */
