/*
** EPITECH PROJECT, 2020
** My Put Uns Bin Int
** File description:
** Prints unsigned int in binary base 0-1
*/

#include <stdlib.h>
#include <stdio.h>

void my_putstr(char const *str);

int my_strlen(char const *str);

char *my_get_str(int nb);

int my_int_len(int num);

static double temp_loop(double temp)
{
    while (temp > 1)
        temp /= 2;
    temp *= 2;
    return (temp);
}

static char to_bin(int check, int num, int caps)
{
    char y = 96;
    unsigned int w = 0;

    if (check == 0)
        w = num / 2;
    if (check == 1)
        w = num % 2;
    if (w > 1)
        return (-1);
    if (w != 0 && w <= 9)
        y = 48 + w;
    if (w == 0)
        y = 48;
    return (y);
}

void my_put_uns_bin_nbr(unsigned int num, int caps)
{
    char *res = malloc(sizeof(char) * (my_int_len(num) + 1));
    int j = 0;
    double temp = num;

    (num > 1) && (temp = temp_loop(temp));
    (num < 2) && (res[0] = to_bin(1, num, caps), res[1] = '\0', j--);
    for (j; temp <= num && j >= 0; j += 2) {
        res[j] = to_bin(0, temp, caps);
        (res[j] == -1) && (j--);
        res[j + 1] = to_bin(1, temp, caps);
        (res[j] == -1) && (j--);
        ((j == 0 && res[j] == '0')) && j--;
        temp *= 2;
    }
    (j >= 0) && (res[j] = '\0');
    my_putstr(res);
    free(res);
    return;
}