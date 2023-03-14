/*
** EPITECH PROJECT, 2021
** lib
** File description:
** my_getstr
*/

#include <stdlib.h>

char *my_getstr(int nb)
{
    int j = 0;
    int i = nb;
    int n = 1;
    char *str;

    for (i = 1; i > 0; i /= n) {
        i = nb;
        if (i == nb)
            n *= 10;
    }
    n /= 10;
    for (int m = n; m > 0; j++, m /= 10);
    str = malloc(sizeof(char) * (j + 1));
    for (j = 0; n > 0; j++, n /= 10)
        str[j] = nb / n % 10 + 48;
    str[j] = '\0';
    return (str);
}
