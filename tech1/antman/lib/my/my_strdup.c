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
    char *str;
    int n;

    str = malloc(sizeof(char) * my_strlen(src) + 1);
    for (n = 0; src[n]; n++)
        str[n] = src[n];
    str[n] = '\0';
    return (str);
}
