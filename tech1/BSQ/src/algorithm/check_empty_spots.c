/*
** EPITECH PROJECT, 2020
** Check empty spots
** File description:
** Checks for empty spots if none returns map as is.
*/

#include "struct.h"

static int weigth(t_table *table, int x, int y)
{
    int a = table->temp[x - 1][y];
    int b = table->temp[x][y - 1];
    int c = table->temp[x - 1][y - 1];

    if (table->temp[x][y] == 0)
        return (0);
    return  ( (a < b && a < c) ? (a)    \
            : (b < a && b <= c) ? (b)   \
            : (c < a && c <= b) ? (c)   \
            : (a));
}

void populate_by_weight(t_table *table)
{
    int x = 1;
    int n = 1;

    for (int y = 1; x < table->x; x++, y = 1) {
        for (; y < table->y; y++)
            if (table->temp[x][y] > 0) {
                (SIZE == 0) && (table->temp[x][y] = 1, y++, LEN);
                (SIZE == 1) && (table->temp[x][y] += weigth(table, x, y), NEXT);
                (table->temp[x][y] > n) && (n = table->temp[x][y],          \
                                            table->temp[0][table->y] = x,   \
                                            table->temp[0][table->y + 1] = y);
            }
    }
    return;
}
