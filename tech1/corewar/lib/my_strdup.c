/*
** EPITECH PROJECT, 2020
** put_nbr
** File description:
** output a number
*/

#include <stdlib.h>

int my_strlen(const char *str);

char *my_strdup(const char *s)
{
    size_t i = 0;
    size_t len = my_strlen(s);
    char *d;

    if (!(d = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    while (i < len) {
        d[i] = s[i];
        i++;
    }
    d[i] = 0;
    return (d);
}
