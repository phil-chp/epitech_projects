/*
** EPITECH PROJECT, 2022
** strace (Workspace)
** File description:
** my_strdup
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int n = 0;
    char *str;

    if (!src) return (NULL);
    str = malloc(my_strlen(src) + 1);
    for (; src[n]; n++)
        str[n] = src[n];
    str[n] = '\0';
    return (str);
}
