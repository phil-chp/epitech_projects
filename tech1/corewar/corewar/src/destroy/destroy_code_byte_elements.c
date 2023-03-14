/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** destroy_code_byte_elements
*/

#include <stdlib.h>

void destroy_code_byte_elements(char *temp, char **res)
{
    for (size_t i = 0; res[i]; i++)
        if (res[i]) free(res[i]);
    if (res) free(res);
}
