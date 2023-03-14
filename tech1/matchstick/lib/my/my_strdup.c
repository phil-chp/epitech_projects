/*
** EPITECH PROJECT, 2020
** My Str Dup
** File description:
** Allocates memory and writes string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strndup(char const c, int n)
{
    int i = 0;
    char *str;

    if (!c) return (NULL);
    str = malloc(sizeof(char) * (n + 2));
    for (; i <= n; i++)
        str[i] = c;
    str[i] = '\0';
    return (str);
}

char *my_strndup_frame(char const frame, char const fill, int n)
{
    int i = 1;
    char *str;

    if (!frame || !fill) return (NULL);
    str = malloc(sizeof(char) * (n + 2));
    str[0] = frame;
    for (; i < n; i++)
        str[i] = fill;
    str[i] = frame;
    str[i + 1] = '\0';
    return (str);
}

char *my_strdup(char const *src)
{
    int n = 0;
    char *str;

    if (!src) return (NULL);
    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    for (; src[n]; n++)
        str[n] = src[n];
    str[n] = '\0';
    return (str);
}
