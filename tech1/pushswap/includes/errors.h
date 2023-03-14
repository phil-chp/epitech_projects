/*
** EPITECH PROJECT, 2020
** pushswap (Workspace)
** File description:
** Errors
*/

#ifndef ERRORS_H_
#define ERRORS_H_

#include <unistd.h>

#define HANDLE  -2147482648

#define ARGS_ERROR write(2, "Error: Not enough arguments.\n", 30)

#endif /* !ERRORS_H_ */
