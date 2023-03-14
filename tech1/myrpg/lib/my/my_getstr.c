/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-myrpg-theo.guichard
** File description:
** my_getstr.c
*/

#include <stdlib.h>

char *my_strdup(char const *src);

void my_putchar(char c);

int my_pow(int j, int b)
{
    int c = 1;
    while (j != 0) {
        c = b * c;
        j--;
    }
    return (c);
}

char *my_getstr(int nb)
{
    int j = 0;
    int i = nb;
    int n = 1;
    char *str;

    if (nb <= 0) return ("0");
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

char *my_get_str_m(int nb, char **str)
{
    int c = nb;
    int i = 0;
    int count = 0;

    if ((*str) != NULL) free(str);
    (*str) = malloc(sizeof(char) * 7);
    if (nb < 0)
        (*str) = my_strdup("0");
    while (nb > 9) {
        nb = nb / 10;
        i++;
    }
    for ( ; i != -1; i--, count++) {
        int b = (c / my_pow(i, 10));
        (*str)[count] = ((b % 10) + 48);
    }
    (*str)[count] = '\0';
    return ((*str));
}
