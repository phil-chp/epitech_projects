/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** Error handling
*/

#ifndef ERROR_H_
#define ERROR_H_

#include <unistd.h>

#define ARGS_ERROR write(2, "Error: wrong arguments.\n", 24), exit(84)
#define PARAM_ERROR write(2, "Error: wrong parameters.\n", 26), exit(84)
#define PERM_DENIED write(2, "Error: permission denied.\n", 27), exit(84)
#define FILE_NOT_FOUND write(2, "Error: no such file or directory.\n", 35), \
                                                                        exit(84)

#endif /* ERROR_H_ */
