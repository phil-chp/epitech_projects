/*
** EPITECH PROJECT, 2020
** Compare
** File description:
** Compares chars and return 1 or 0 if they match or not
*/

#include "my.h"

int compare(char *a, char *b)
{
    int len1 = my_strlen(a);
    int len2 = my_strlen(b);

    if (len1 != len2)
        return (0);
    else {
        if (my_strcmp(a, b) == 0) {
            return (1);
        } else {
            return (0);
        }
    }
}
