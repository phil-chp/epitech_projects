/*
** EPITECH PROJECT, 2021
** corewar (Workspace)
** File description:
** check_dot_cor
*/

#include <stdbool.h>
#include <stddef.h>

bool check_dot_cor(char *param, size_t cor)
{
    char correct[] = ".cor\0";

    for (size_t i = 0; param[i] && correct[i]; i++) {
        if (param[i + cor] != correct[i])
            return (1);
    }
    return (0);
}
