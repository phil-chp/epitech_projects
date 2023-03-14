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
    int x = 0;

    if (str[n] == '\0' && to_find[x] == '\0')
        return (str);
    for (int m = 0; str[n] != '\0'; n = m + 1) {
        m = n;
        for (x = 0; str[n] == to_find[x] && to_find[x] != '\0'; n++, x++);
        if (to_find[x] == '\0')
            return (&str[m]);
    }
    return (NULL);
}
