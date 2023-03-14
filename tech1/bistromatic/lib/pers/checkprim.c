/*
** EPITECH PROJECT, 2020
** Checkprim
** File description:
** Checks for multiplication, division and modulo
*/

#include <stdlib.h>

int compare(char *a, char *b);

int checkprim(char **T, int open, int close)
{
    int i = open;

    while (i < close) {
        if (compare(T[i], "*") == 1 || compare(T[i], "/") == 1 \
            || compare(T[i], "%") == 1)
            return (i);
        i++;
    }
    return (0);
}
