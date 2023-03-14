/*
** EPITECH PROJECT, 2021
** my_strcat_malloc
** File description:
** Concatenates Strings
** ex:
**    char a = "123";
**    char b = "456";
** .
**    a = my_strcat(a, b);
** a -> "123456"
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat_malloc(char *dest, char const *src)
{
    int d_len = 0;
    int s_len = 0;
    char *res;

    d_len = my_strlen(dest);
    s_len = my_strlen(dest);
    res = malloc(sizeof(char) * (d_len + s_len + 1));
    for (int i = 0; dest[i]; i++)
        res[i] = dest[i];
    if (dest) free(dest);
    for (int j = 0; src[j]; j++, d_len++)
        res[d_len] = src[j];
    res[d_len] = '\0';
    return (res);
}
