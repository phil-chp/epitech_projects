/*
** EPITECH PROJECT, 2020
** Get Str
** File description:
** My get str from int
*/

#include <stdlib.h>

int my_int_len(int num);

char *my_get_str(int nb)
{
    char *str = malloc(sizeof(char) * my_int_len(nb) + 1);
    int j = 0;
    int a = 0;
    int n;

    if (nb == 0)
        return ("0");
    (nb < 0) && (str[0] = '-', nb *= -1, j++);
    a += my_int_len(nb);
    for (n = 1; a > 1; a--)
        n *= 10;
    for (j; n != 0; j++) {
        str[j] = nb / n % 10 + 48;
        n /= 10;
    }
    str[j] = '\0';
    return (str);
}