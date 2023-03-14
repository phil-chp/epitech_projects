/*
** EPITECH PROJECT, 2021
** clean_str
** File description:
** error messages and return values
*/

#ifndef ERRORS_H_
#define ERRORS_H_

#include <unistd.h>

#define NOT_ENOUGH_ARGS write(2, "Clean str: missing arguments\n", 29);

#define SUCCESS_CODE  0
#define ERROR_CODE    84
#define ERROR_NULL    NULL

#endif /* ERRORS_H_ */
