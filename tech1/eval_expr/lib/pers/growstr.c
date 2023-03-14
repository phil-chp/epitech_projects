/*
** EPITECH PROJECT, 2020
** growstr return a string and complete with '0' until reach the size
** File description:
** ex growstr("456", 5) -> 00456
*/

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "pers.h"

char *growstr(char *str, int size)
{
    char *empty = "0";
    char *strc = malloc(sizeof(char) * (size * 2));
    int a = my_strlen(str);
    int i = 0;
    strc[0] = 0;
    while (i != size-a) {
        strc = my_strcat(strc, empty);
        a++;
    }
    strc = my_strcat(strc, str);
    strc[a] = '\0';
    return strc;
}
