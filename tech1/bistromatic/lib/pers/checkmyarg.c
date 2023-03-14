/*
** EPITECH PROJECT, 2020
** checkmyarg
** File description:
** return error if no there is an char non numerique only 1234567890-
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "pers.h"

int checkmyarg(char *str)
{
    int i = 0;
    int test = 0;

    while (str[i] != '\0') {
        (str[i] == 45 || (str[i] <= 57 && str[i] >= 48)) ? 0 : (test++);
        i++;
    }
    return (test);
}
