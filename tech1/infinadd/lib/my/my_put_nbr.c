/*
** EPITECH PROJECT, 2020
** My Put Nbr
** File description:
** Puts Numbers
*/

#include <unistd.h>

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int n = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb > 9)
        my_put_nbr(nb / 10);
    n = nb % 10;
    my_putchar(n + '0');
    return (0);
}
