/*
** EPITECH PROJECT, 2021
** n4s
** File description:
** dump_terminal
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool dump_terminal(void)
{
    char *output = NULL;
    size_t size = 0;

    if (getline(&output, &size, stdin) == -1)
        return (1);
    free(output);
    return (0);
}
