/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** free_tab
*/

#include <stdlib.h>

void free_tab(char ***tab)
{
    for (size_t i = 0; (*tab)[i]; i++)
        if ((*tab)[i]) free((*tab)[i]);
    if (*tab) free(*tab);
}
