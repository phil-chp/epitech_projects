/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** task05
*/

int my_getnbr(char *str)
{
    int i = 0;
    int nb = 0;
    int sign = 1;
    int n = 0;

    while (str[i] != '\0' && (str[i] <= '0' || str[i] > '9')) {
        if (str[i] == '-')
            sign = sign * -1;
        i++;
    }
    if (str[i] == '\0')
        return (0);
    while (str[i] != '\0' && (str[i] <= '9' && str[i] >= '0')) {
        if ((nb == 214748364 && str[i] - 48 > 7) || nb > 214748364 || n > 10)
            return (0);
        nb = nb * 10 +(str[i] - '0');
        i++;
        n++;
    }
    return (nb * sign);
}
