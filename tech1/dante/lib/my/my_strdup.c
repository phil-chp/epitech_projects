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

    if (!src) return (NULL);
    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    for (; src[n]; n++)
        str[n] = src[n];
    str[n] = '\0';
    return (str);
}

char *my_strdup_char(char const c, int n)
{
    int i = 0;
    char *str;

    if (!c || n < 1)
        return (NULL);
    str = malloc(sizeof(char) * (n + 1));
    for (; i < n; i++)
        str[i] = c;
    str[i] = '\0';
    return (str);
}

char *my_strndupm(char const *src, int n, int m)
{
    int i = 0;
    char *str;

    if (!src) return (NULL);
    str = malloc(sizeof(char) * (m - n + 1));
    for (; src[n] && n < m; n++, i++)
        str[i] = src[n];
    str[i] = '\0';
    return (str);
}
