/*
** EPITECH PROJECT, 2020
** My Str Dup
** File description:
** Allocates memory and writes string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int n = 0;
    char *str;

    if (!src)
        return (NULL);
    if (!(str = malloc(my_strlen(src) + 1)))
        return (NULL);
    for (; src[n]; n++)
        str[n] = src[n];
    str[n] = '\0';
    return (str);
}
