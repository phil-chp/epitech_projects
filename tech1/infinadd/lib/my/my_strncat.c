/*
** EPITECH PROJECT, 2020
** My Str N Cat
** File description:
** Concatenates n Chars of a String to Another
*/

#include <stdio.h>

char *my_strncat(char *dest, char const *src, int nb)
{
    int n = 0;

    while (dest[n] != '\0')
        n++;
    for (int a = 0; a < nb && src[a] != '\0'; a++, n++) {
        dest[n] = src[a];
    }
    dest[n] = '\0';
    return (dest);
}
