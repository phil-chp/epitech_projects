/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** my_strcmp
*/

#include <stddef.h>

int my_strcmp(char const *s1, char const *s2)
{
    size_t i = 0;

    for (; s1[i] && s1[i] == s2[i]; ++i);
    return (s1[i] - s2[i]);
}
