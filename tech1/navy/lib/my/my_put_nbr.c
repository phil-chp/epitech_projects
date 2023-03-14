/*
** EPITECH PROJECT, 2020
** navy
** File description:
** my_put_nbr
*/

#include <unistd.h>

void my_putchar(char c);

int my_put_nbr(int nb)
{
    long nbl = nb;
    int p = 0;
    if (nbl < -2147483648 || nbl > 2147483647)
        return (0);
    if (nbl < 0) {
        my_putchar('-');
        nbl = -nbl;
    }
    if (nbl > 9)
        my_put_nbr(nbl / 10);
    p = nbl % 10;
    my_putchar(p + 48);
    return (0);
}
