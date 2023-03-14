/*
** EPITECH PROJECT, 2021
** solostumper02
** File description:
** utils header file
*/

#ifndef UTILS_H_
#define UTILS_H_

#ifndef MACROS_H_
#define MACROS_H_

#include <unistd.h>

#define BAD_ARGS      write(2, "Error: missing arguments.\n", 26);

#define ERROR_CODE    84
#define NOT_PAL       1
#define SUCCESS_CODE  0

#endif /* MACROS_H_ */

int palindrome(char *word);

#endif /* UTILS_H_ */
