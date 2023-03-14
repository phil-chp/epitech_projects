/*
** EPITECH PROJECT, 2020
** checkzero retire '0'
** File description:
** ex str = "000567" checkzero -> "567"
*/

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "pers.h"

char *checkzero(char *str)
{
    int i = 0, a = 0, count = 0, u = my_strlen(str);
    char *s;

    s = "0";
    while (str[a] != '\0') {
        if (str[a] == '0')
            count++;
        a++;
    }
    if (count == a)
        return (s);
    else {
        while (i != u)
            i++;
        i--;
        while (str[i] == '0')
            i--;
        str[i + 1] = '\0';
        return (str);
    }
}
