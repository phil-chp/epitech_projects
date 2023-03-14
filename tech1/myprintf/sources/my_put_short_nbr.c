/*
** EPITECH PROJECT, 2020
** My Put Short Nbr
** File description:
** Puts Short Numbers
*/

#include <unistd.h>

void my_putchar(char const c);

int my_put_short_nbr(short int short_nb)
{
    int nb = short_nb;
    int n = 0;

    if (nb < -32768)
        nb = 32767 - nb;
    if (nb > 32767)
        nb = -32767 + nb;
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb > 9)
        my_put_short_nbr(nb / 10);
    n = nb % 10;
    my_putchar(n + '0');
    return (0);
}
