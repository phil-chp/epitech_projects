/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** my_strlen
*/

#include <stddef.h>

size_t my_strlen(char const *str)
{
    int i = 0;

    for (; str[i]; ++i);
    return (i);
}
