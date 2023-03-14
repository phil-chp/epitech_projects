/*
** EPITECH PROJECT, 2020
** my put long uns nbr
** File description:
** my put long uns nbr
*/

void my_putchar(char const c);

void my_put_long_uns_nbr(unsigned long ul_nb)
{

    unsigned long long int nb = ul_nb;
    int n = 0;

    if (nb < -18446744073709551615U)
        nb = 18446744073709551615U - nb;
    if (nb > 18446744073709551615U)
        nb = -18446744073709551615U + nb;
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb > 9)
        my_put_long_uns_nbr(nb / 10);
    n = nb % 10;
    my_putchar(n + '0');
    return;
}