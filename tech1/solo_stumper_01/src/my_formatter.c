/*
** EPITECH PROJECT, 2021
** clean_str
** File description:
** Takes a char * and returns a cleaned version of itself
*/

#include <stdio.h>
#include <stdlib.h>
#include "includes/my.h"

char *my_formatter(char *str)
{
    char *result;
    int space = 0;
    int i;
    int len;
    int k = 0;

    len = my_strlen(str);
    for (i = 0; i < len; i++, space = 0) {
        for (; str[i - 1] == ' '; i--);
        for (; str[i] && (str[i] == ' ' || str[i] == '\t'); i++, space++);
        if (space >= 1 && k != 0) result[k++] = ' ';
        while (space >= 1) {
            result[k++] = str[i++];
            space--;
        }
        result[k++] = str[i];
    }
    result[k] = '\0';
    return (result);
}
