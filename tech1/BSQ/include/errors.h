/*
** EPITECH PROJECT, 2020
** Error
** File description:
** Error handling
*/

#ifndef ERROR_H_
#define ERROR_H_

#include <unistd.h>

#define WRONG_PARAMS    84
#define MEMORY          84
#define NOT_A_FILE      84
#define CORRUPT_TABLE   84

#define ERROR           (write(2, "BSQ: Error\n", 12) == -1)
#define SYNTAX_ERROR    (write(2, "BSQ: Syntax error\n", 19) == -1)
#define MEM_ERROR       (write(2, "BSQ: Memory error\n", 19) == -1)

#endif /* ERROR_H_ */
