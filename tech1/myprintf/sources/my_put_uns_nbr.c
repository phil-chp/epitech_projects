/*
** EPITECH PROJECT, 2020
** My put uns int
** File description:
** My Put unsigned int
*/

#include <unistd.h>

void my_putchar(char const c);

int my_put_uns_nbr(unsigned int nb)
{
    unsigned long long_nb = nb;
    int n = 0;

    if (long_nb < 0)
        long_nb = 4294967295 - long_nb;
    if (long_nb > 4294967295)
        long_nb  = 0 + long_nb;
    if (long_nb > 9)
        my_put_uns_nbr(long_nb / 10);
    n = long_nb % 10;
    my_putchar(n + '0');
    return (0);
}
