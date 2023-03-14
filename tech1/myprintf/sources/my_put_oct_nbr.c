/*
** EPITECH PROJECT, 2020
** My Put Uns Hex Int
** File description:
** Prints hnsigned int in hex base 0-F
*/

#include <stdlib.h>
#include <stdio.h>

void my_putstr(char const *str);

int my_strlen(char const *str);

char *my_get_str(int nb);

int my_int_len(int num);

static void utils_end(char *res)
{
    my_putstr(res);
    free(res);
    return;
}

static double temp_loop(double temp)
{
    while (temp > 7)
        temp /= 8;
    temp *= 8;
    return (temp);
}

char int_to_oct(int check, int num)
{
    char y = 96;
    unsigned int w = 0;

    if (check == 0)
        w = num / 8;
    if (check == 1)
        w = num % 8;
    if (w > 7)
        return (-1);
    if (w != 0 && w <= 9)
        y = 48 + w;
    if (w == 0)
        y = 48;
    return (y);
}

void my_put_oct_nbr(unsigned int num)
{
    char *res = malloc(sizeof(char) * (my_int_len(num) + 1));
    double temp;
    int j = 0;

    (num < 0) && (num = -num, res[j] = '-', j++);
    temp = num;
    (num > 7) && (temp = temp_loop(temp));
    (num < 8) && (res[j] = int_to_oct(1, num), res[j + 1] = '\0', j = -1);
    for (int i = 0; temp <= num && j >= 0; i++, j += 2) {
        res[j] = int_to_oct(0, temp);
        (res[j] == -1) && (j--);
        res[j + 1] = int_to_oct(1, temp);
        (res[j + 1] == -1) && (j--);
        ((j == 0 && res[j] == '0')) && (j--);
        temp *= 8;
    }
    (j >= 0) && (res[j] = '\0');
    utils_end(res);
    return;
}