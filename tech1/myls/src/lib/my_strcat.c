/*
** EPITECH PROJECT, 2020
** My Str Cat
** File description:
** Concatenates Strings
*/

#include <stdio.h>

void my_putstr(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int n = 0;

    while (dest[n] != '\0')
        n++;
    for (int a = 0; src[a] != '\0'; a++, n++)
        dest[n] = src[a];
    dest[n] = '\0';
    return (dest);
}
