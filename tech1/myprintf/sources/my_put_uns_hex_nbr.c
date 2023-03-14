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

static double temp_loop(double temp)
{
    while (temp > 16)
        temp /= 16;
    temp *= 16;
    return (temp);
}

static char to_hex(int check, int num)
{
    char y = 96;
    unsigned int w = 0;

    if (check == 0)
        w = num / 16;
    if (check == 1)
        w = num % 16;
    if (w > 15)
        return (-1);
    if (w != 0 && w <= 9)
        y = 48 + w;
    if (w > 9) {
        w -= 9;
        y += w;
    }
    if (w == 0)
        y = 48;
    return (y);
}

void my_put_uns_hex_nbr(unsigned int num)
{
    char *result = malloc(sizeof(char) * (my_int_len(num) + 1));
    int j = 0;
    double temp = num;

    (num > 16) && (temp = temp_loop(temp));
    (num < 16) && (result[0] = to_hex(1, num), result[1] = '\0', j--);
    for (int i = 0; temp <= num && j >= 0; i++, j += 2) {
        result[j] = to_hex(0, temp);
        (result[j] == -1) && (j--);
        result[j + 1] = to_hex(1, temp);
        (result[j + 1] == -1) && (j--);
        ((j == 0 && result[j] == '0')) && j--;
        temp *= 16;
    }
    (j >= 0) && (result[j] = '\0');
    my_putstr(result);
    free(result);
    return;
}