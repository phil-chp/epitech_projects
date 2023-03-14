/*
** EPITECH PROJECT, 2020
** only numb without '-'
** File description:
** onlynumb delete the first char; ex : str = '-456'
** onlynumb -> 456  warning : '456' -> '56'
*/

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "pers.h"

char *onlynumb(char *str)
{
    char *t;
    int i = 1;
    int j = 0;

    t = malloc(sizeof(char) * (my_strlen(str) + 1));
    while (str[i] != '\0') {
        t[j] = str[i];
        i++;
        j++;
    }
    t[j] = '\0';
    return (t);
}
