/*
** EPITECH PROJECT, 2020
** My Str Str
** File description:
** Compares String to Substring
*/

#include <stdlib.h>
#include <stdio.h>

char *my_strstr(char *str, char const *to_find)
{
    int n = 0;
    int m = 0;
    int x = 0;

    if (str[n] == '\0' && to_find[x] == '\0')
        return (str);
    while (str[n] != '\0') {
        m = n;
        x = 0;
        while (str[n] == to_find[x] && to_find[x] != '\0') {
            n++;
            x++;
        }
        if (to_find[x] == '\0')
            return (&str[m]);
        n = m + 1;
    }
    return (NULL);
}
