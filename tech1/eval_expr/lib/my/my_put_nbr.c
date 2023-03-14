/*
** EPITECH PROJECT, 2020
** myputnbr
** File description:
** disp numb
*/

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

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    int c = nb;
    int i = 0;
    while (nb > 9) {
        nb = nb / 10;
        i++;
    }
    while (i != -1) {
        int b = (c / my_pow(i, 10));
        my_putchar((b % 10) + 48);
        i--;
    }
}
