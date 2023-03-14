/*
** EPITECH PROJECT, 2021
** antman
** File description:
** parse_word
*/

#include <stdlib.h>

char *parse_word(int start, int end, char *src)
{
    char *res;
    int temp;
    int i;

    temp = end - start;
    res = malloc(sizeof(char) * (temp + 5));
    for (i = 0; start <= end; start++, i++)
        res[i] = src[start];
    res[i] = '\0';
    return (res);
}
