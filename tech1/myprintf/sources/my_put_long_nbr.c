/*
** EPITECH PROJECT, 2020
** My put long number
** File description:
** My put long number
*/

void my_putchar(char const c);

int my_put_long_nbr(long int long_nb)
{
    long long int ll_nb = long_nb;
    int n = 0;

    if (ll_nb < -9223372036854775807)
        ll_nb = 9223372036854775807 - ll_nb;
    if (ll_nb > 9223372036854775807)
        ll_nb = -9223372036854775807 + ll_nb;
    if (ll_nb < 0) {
        my_putchar('-');
        ll_nb = -ll_nb;
    }
    if (ll_nb > 9)
        my_put_long_nbr(ll_nb / 10);
    n = ll_nb % 10;
    my_putchar(n + '0');
    return (0);
}