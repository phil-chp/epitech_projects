/*
** EPITECH PROJECT, 2020
** checksize compare two string
** File description:
** ex checksize (s1, s2) s1>s2 ->1. s2>s1 -> 2. s1 = s2 -> 0;
*/

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "pers.h"

int checksize(char *str, char *str2)
{
    int len1, len2, a = 0;
    len1 = my_strlen(str);
    len2 = my_strlen(str2);

    if (len1 < len2)
        return (1);
    if (len1 > len2)
        return (2);
    else {
        if (my_strcmp(str, str2) == 0)
            return (0);
        if (my_strcmp(str, str2) < 0)
            return (1);
        else
            return (2);
    }
}
