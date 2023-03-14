/*
** EPITECH PROJECT, 2020
** B-CPE-201-NCE-2-1-corewar-philippe.cheype
** File description:
** get_op_code.c
*/

#include "corewar.h"
#include <stdlib.h>

static void check_command(char *op_code, int (*nb)[2])
{
    char *command[] =   {                               \
                "0", "1", "2", "3", "4", "5", "6", "7", \
                "8", "9", "a", "b", "c", "d", "e", "f"  \
                        };

    for (size_t i = 0; i < 16; i++) {
        if (op_code[0] == command[i][0])
            (*nb)[0] = i;
        if (op_code[1] == command[i][0])
            (*nb)[1] = i;
    }
}

char **my_op_code_converter(char *op_code)
{
    int nb[] = { 0, 0 };
    char **res = NULL;
    int temp = 0;
    ssize_t i, n;
    bool k;

    if (!(res = malloc(sizeof(char *) * 5))) return (NULL);
    check_command(op_code, &nb);
    for (i = 3; i >= 0; i--) {
        k = (i > 1 ? 1 : 0);
        if (!(res[i] = malloc(sizeof(char) * 5))) return (NULL);
        for (n = 1; n >= 0; n--) {
            temp = nb[k] % 2;
            nb[k] /= 2;
            res[i][n] = temp + 48;
        }
        res[i][2] = '\0';
    }
    return (res);
}
