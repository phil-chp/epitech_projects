/*
** EPITECH PROJECT, 2020
** put_nbr
** File description:
** output a number
*/

int my_putchar(char c);

void put_nbr(long long nb)
{
    char c;

    if (nb < 0) {
        nb *= -1;
        c = '-';
        my_putchar(c);
    }
    if (nb <= 9) {
        c = nb + 48;
        my_putchar(c);
    } else if (nb >= 10) {
        put_nbr(nb / 10);
        c = (nb % 10) + 48;
        my_putchar(c);
    }
}
